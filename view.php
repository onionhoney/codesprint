<?php
   include("./config.php");
   include("./Parsedown.php");

if (!isset($_GET["problem"])) {  //|| $_SESSION["contest_starts"] == 0) {
    exit("You do not have access to the file.");
}
else {
    $letter = $_GET["problem"];
    // get prereqs for that letter
    // $team_solved = $_SESSION["solved".$_SESSION["teamid"]]; //$_SESSION["scores"][$team]->solved($letter);//
    // if (!isset($_SESSION["contest"])) {
    //     exit("Error: contest has not been set");
    // }
    // $contest = $_SESSION["contest"];//->problemprereq($letter);
    // $problem_prereqs = $contest;//[$letter];//->problemprereq($letter);//["pprereqs"];
    // // $problem_prereqs = $contest["pprereqs"][$letter];
    // var_dump($contest);
    // var_dump($problem_prereqs);
    // //if not all the prereqs are satisfied, exit
    // foreach ($problem_prereqs as $prereq)
    // {
    //     if($prereq == "--")
    //         continue;
    //     if(!in_array($prereq, $team_solved))
    //         exit("You must first solve " . $problem_prereqs . ". You haven't solved " . $prereq);
    // }

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
