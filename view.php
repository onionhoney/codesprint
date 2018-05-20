<?php
   include("./config.php");
   include("./Parsedown.php");
   include("./common.php");

if (!isset($_GET["problem"])) {  //|| $_SESSION["contest_starts"] == 0) {
    exit("You do not have access to the file.");
}
else {
    $letter = $_GET["problem"];
    // get prereqs for that letter
    // what teamname is associated to this teamid?
    $contest = new Contest($g_configfile, $g_problempath);

    $problem_prereqs = $contest->problemprereq($letter);
    $team_solved = array();
    $teamname = $_SESSION["teamid"];
    if ($teamname == "")
        exit("You must login.");
    // Read g_solvedfile
    if ($contest->tnow < $contest->tstart)
        exit("Nice try.. think you can access problems before the contest starts?");
    if ($contest->okay)
    {
       if ($fp = fopen($g_solvedfile, "r"))
       {
          flock($fp, LOCK_SH);

          // read the file
          while ($line = fgets($fp))
          {
             list($s_teamname, $problems) = explode(";", trim($line));
             if ($s_teamname == $teamname)
                $team_solved = explode(",", $problems);
                break;
          }

          fclose($fp);
       }
   }
   //echo "Team solved: "; print_r($team_solved);
   //echo "<br>Problem prereqs: "; print_r($problem_prereqs);

    //if not all the prereqs are satisfied, exit
    foreach ($problem_prereqs as $prereq)
    {
        if($prereq == "--")
            continue;
        if(!in_array($prereq, $team_solved))
            exit("You must first solve [" . implode(',', $problem_prereqs) . "]. You haven't solved " . $prereq);
    }

    $title = Problem . " " . $letter;
    $text = file_get_contents($g_problempath . $letter.".txt");
}
?>

<!doctype html>
<html>
<head>
  <meta charset="utf-8"/>
  <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/github-markdown-css/2.4.1/github-markdown.min.css">
  <style>
.markdown-body {
        box-sizing: border-box;
        min-width: 200px;
        max-width: 980px;
        margin: 0 auto;
        padding: 45px;
    }
  </style>

  <script type="text/x-mathjax-config">
MathJax.Hub.Config({tex2jax: {
inlineMath: [['$','$'], ['\\(','\\)']],
    displayMath: [ ['$$','$$'], ["\\[","\\]"] ],
}});
  </script>
  <script type="text/javascript" async
    src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS_CHTML">
  </script>

  <?php echo "<title> $title </title>" ?>
</head>
<body>
<div class="markdown-body">
<?php
    $Parsedown = new Parsedown();
    echo $Parsedown->text($text);
?>
</div>

</body>
</html>
