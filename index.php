<?php
// This line is edited remotedly! 
?>
<?php
   include("./config.php");
   include("./common.php");
?>

<html>

<head>
<?php print "<title>$g_pagetitle</title>\n"; ?>
</head>

<body>

<div align="center">
<h1><?=$g_pagetitle?></h1>
<!--<h2><i>Online Training Arena</i></h2> -->
<h2><i> Hosted by ACM-ICPC </i></h2>
<p><img src="images/icpc_logo.png"></p>
</div>

<?php navigation("index"); ?>

<hr>
<div align="center">

<?php   
   // just make sure the submitfile and judgefile are there
   if (!file_exists($g_submitfile))
   {
      $fp = fopen($g_submitfile, "w");
      fclose($fp);
      chmod($g_submitfile, 0660);
   }
   if (!file_exists($g_judgefile))
   {
      $fp = fopen($g_judgefile, "w");
      fclose($fp);
      chmod($g_judgefile, 0660);
   }
   
   $contest = new Contest($g_configfile, $g_problempath);
   if ($contest->okay)
   {
      print "<p>Contest of $contest->cdate<br>\n";
      print "<i>$contest->ctime</i></p>\n";

      print "<table border=\"0\" width=\"320\">\n";
      print "<tr><th>$contest->cname</th></tr>\n";
      if ( ! session_id() ) @ session_start();

      if ($contest->tnow >= $contest->tstart) {
          $_SESSION["contest_starts"] = 1;
      }
      else {
          $_SESSION["contest_starts"] = 0;
      }

      foreach ($contest->pletters as $letter)
      {
         //$link = $g_problempath."all.php";
         $link = $contest->problemlonglink($letter);
         $name = $contest->pnames[$letter];
         if ($_SESSION["contest_starts"] == 1) {
print <<<END
    <tr><td> 
        <form id="form$letter" action="view.php?problem=$letter" method="get" > </form>
        <a href="view.php?problem=$letter" target="_blank" style="text-align:left; display:block" >
            Problem $name ($g_pv[$letter])
        </a>
    </td></tr>
END;
         }
         else {
print <<<END
    <tr><td> Problem $letter </td></tr>
END;
         }
      }
      print "</table>\n";
      
      print "<p><i>For your questions, comments, and issues,<br>\n";
      print "please contact your host today at</i><br>\n";
      print "<a href=\"mailto:$contest->chost\">$contest->chost</a></p>\n";      

      // unlock (or relock) the problem set if necessary
      if ($contest->tnow > $contest->tstart)
      {
         if (file_exists($g_problempath . ".htaccess"))
            rename($g_problempath . ".htaccess", $g_problempath . ".lock");
      }
      else
      {
         if (file_exists($g_problempath . ".lock"))
            rename($g_problempath . ".lock", $g_problempath . ".htaccess");
      }
   }
?>
<p>Current date and time:<br>
<i><?=date("r")?></i></p>
</div>

<?php footer(); ?>

</body>

</html>
