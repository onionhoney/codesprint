<?php
   chdir("../");
   include("config.php");
   include("common.php");

   // process the POST data right away if any, and send a refresh header
   if ($_POST["contest"] && false)
   {
      echo '<script language="javascript">';
      echo 'alert("'. $_SESSION["current_session"] . '")';
      echo '</script>';
   }
      //header("Location: jconfig.php");
      //exit("Debug information.");
   if ($_POST["contest"]) 
   {
      $current_configfile = $_SESSION["current_session"] . "config.txt";
      // write the contest information to file
      if ($fp = fopen($current_configfile, "w"))
      {
         flock($fp, LOCK_EX);
         fputs($fp, stripcslashes($_POST["title"]) . "\n");
         fputs($fp, stripcslashes($_POST["chost"]) . "\n");
         fputs($fp, sprintf("%s %s %s\n", $_POST["cddate"], $_POST["cdmonth"], $_POST["cdyear"]));
         fputs($fp, sprintf("%02d:%02d + %02d:%02d\n",
                            $_POST["cdhour"], $_POST["cdminute"],
                            $_POST["clhours"], $_POST["clminutes"]));
         fputs($fp, implode(";", array($_POST["freeze"], $_POST["firstletter"], $_POST["showtitle"])) . "\n");
         fputs($fp, stripcslashes($_POST["cname"]) . "\n");

         // write up to 12 problems to configuration file
         for ($i = 1; $i <= 10; $i++)
            if ($_POST["problem".$i])
            {
               $name = stripcslashes($_POST["problem".$i]);
               $letter = $_POST["problem".$i."-u"];
               $url = $letter;

               $filename = $_FILES["problem".$i."-f"]["name"];

               $inputname = ($_FILES["input".$i."-f"]["name"] == "") ? "" : $letter . ".in"; //$_FILES["input".$i."-f"]["name"];
               $outputname = ($_FILES["output".$i."-f"]["name"] == "") ? "" : $letter . ".out"; //$_FILES["output".$i."-f"]["name"];

               $prereq = $_POST["prereq".$i];
               $tlimit = $_POST["tlimit".$i];
               /*
               if ($i == 1){
                   $prereq = "--";    // hardcoded default prereqs, until we add the feature to the front-end
               }
               else {
                   $prereq = implode(",", range('A', chr(ord('A')+$i-2)));
               }
                */
               fputs($fp, sprintf("%-30s;%-10s;%-10s;%-10s\n", $name, $url, $prereq, $tlimit));


               if ($url && $filename)
               {
                  $tempname = $_FILES["problem".$i."-f"]["tmp_name"];
                  if (!move_uploaded_file($tempname, $g_problempath . $url . '.txt'))
                     $_SESSION["error"] = "<center><p><font color=\"red\">Unable to save file $filename in $g_problempath$url. </font></p></center>\n";
               }
               if ($url && $inputname)
               {
                   $tempname = $_FILES["input".$i."-f"]["tmp_name"];
                   if (!move_uploaded_file($tempname, $g_testcasepath . $inputname))
                     $_SESSION["error"] = "<center><p><font color=\"red\">Unable to save file $inputname in $g_testcasepath$inputname. </font></p></center>\n";
               }
               if ($url && $outputname)
               {
                   $tempname = $_FILES["output".$i."-f"]["tmp_name"];
                   if (!move_uploaded_file($tempname, $g_testcasepath . $outputname))
                     $_SESSION["error"] = "<center><p><font color=\"red\">Unable to save file $outputname in $g_testcasepath$outputname. </font></p></center>\n";
               }
            }

         fclose($fp);

         // unpack an uploaded archive if there is one
         if ($_FILES["archive"]["name"])
         {
            $archive = $g_problempath . "archive.zip";
            if (move_uploaded_file($_FILES["archive"]["tmp_name"], $archive))
            {
               exec("unzip $archive -d $g_problempath");
               unlink($archive);
            }
         }

         $_SESSION["savedc"] = True;
         header("Location: jconfig.php");
         exit("Saved contest information.");
      }
      else
      {
         $_SESSION["error"] = "<center><p><b><font color=\"red\">Unable to save contest!</font></b></p></center>\n";
      }
   }

   if ($_POST["teams"])
   {
      // save team information to team file
      $current_teamfile = $_SESSION["current_session"] . "teams.txt";
      if ($fp = fopen($current_teamfile, "w"))
      {
         flock($fp, LOCK_EX);
         for ($i = 1; $i <= 100; $i++)
         {
            $key = "team" . $i;
            if ($_POST[$key])
            {
               $team       = $_POST[$key];
               $passwd     = $_POST[$key . "-p"];
               $official   = $_POST[$key . "-o"];
               $name       = $_POST[$key . "-n"];
               $members    = $_POST[$key . "-m"];
               $line = implode(";", array($team, $passwd, $official, $name, $members));
               fputs($fp, stripcslashes($line) . "\n");
            }
         }
         fclose($fp);

         $_SESSION["savedt"] = True;
         header("Location: jconfig.php");
         exit("Saved team information.");
        }
      else
      {
         $_SESSION["error"] = "<center><p><b><font color=\"red\">Unable to save teams!</font></b></p></center>\n";
      }
   }

   // NEW: SWITCH CONTEST
   if ($_POST["switch"])
   {
       $arr = file($g_sessionsfile);
       $arr[0] = $_POST["which_contest"]."\n";
       file_put_contents($g_sessionsfile, implode($arr));
       $_SESSION["saveds"] = True;
       header("Location: jconfig.php");
       exit("Switched session.");
   }
?>

<html>

<head>
    <?php headerer($g_pagetitle); ?>
</head>

<body>


<?php jnavigation("jconfig"); ?>
<div class="container text-center" style='padding-top:5em;'>
<h1>Judge Contest Configuration</h1>




<?php
   // if an error occurred while processing POST data, display it here
   if ($_SESSION["error"])
   {
      print "<hr>\n";
      print $_SESSION["error"];
      unset($_SESSION["error"]);
   }
?>


<!-- ---------- CONTEST & PROBLEM SET ---------- -->


<p><b><big>Session Switching</big></b></p>

<?php
   print "<p>You are working on session ".$g_sessionpath."\n";
   $_SESSION["current_session"] = $g_sessionpath;
?>
<?php
   if (isset($_SESSION["saveds"]))
   {
      print "<p><font color=\"green\">Session successfully switched.</font></p>\n";
      unset($_SESSION["saveds"]);
   }
?>

<?php
if ($fp = fopen($g_sessionsfile, "r"))
    {
        flock($fp, LOCK_SH);
        // read contest names and URLs
        $contests = array();
        $currname = fgets($fp);
        while ($line=fgets($fp))
            $contests[] = trim($line);
        fclose($fp);


print <<<END
    <form name="switch" method="post" action="jconfig.php" ">
       <select name="which_contest">

END;

        foreach($contests as $idx => $contest) {
            $line = explode(";", $contest);
            $name = htmlspecialchars(trim($line[0]));
            $url  = trim($line[1]);
            $sel = ($url == trim($currname)) ? "selected=\"selected\"" : "";
            printf("          <option value=\"%s\" $sel>%s</option>\n", $url, $name);
        }
print <<<END
       </select>
       <p><input type="submit" name="switch" value="Switch to Session"/></p>
    </form>
END;

    }

?>

<p><b><big>Contest & Problem Set</big></b></p>

<?php
   if (isset($_SESSION["savedc"]))
   {
      print "<p><font color=\"green\">Contest and problem set information saved.</font></p>\n";
      unset($_SESSION["savedc"]);
   }

   // load configuration values from file
   if ($fp = fopen($g_configfile, "r"))
   {
      flock($fp, LOCK_SH);

      // read page title and contest host contact
      $title = htmlspecialchars(trim(fgets($fp)));
      $chost = htmlspecialchars(trim(fgets($fp)));

      // read contest date and tiem
      list($cddate, $cdmonth, $cdyear) = fscanf($fp, "%d %s %d\n");
      list($cdhour, $cdminute, $clhours, $clminutes) = fscanf($fp, "%d:%d + %d:%d\n");

      // read scoreboard freeze, first letter, and show titles
      list($freeze, $firstletter, $showtitle) = explode(";", trim(fgets($fp)));
      $showtitle = $showtitle ? "checked=\"checked\"" : "";

      // read problem set name
      $cname = htmlspecialchars(trim(fgets($fp)));

      // read problem names and URLs
      $problems = array();
      while ($line = fgets($fp))
         $problems[] = trim($line);

      fclose($fp);
   }

// ----- HTML -----
print <<<END
<form name="contest" method="post" action="jconfig.php" enctype="multipart/form-data">
<div class="container"> 
   <div class="row"><div class="col-2"> </div> 
   <div class="col-8">
<table cellpadding="2" class="">
   <tr>
      <td>Page Title</td>
      <td><input class="" type="text" name="title" size="30" value="$title" /></td>
   </tr>
   <tr>
      <td>Host Contact</td>
      <td><input class="" type="text" name="chost" size="30" value="$chost" /></td>
   </tr>
   <tr>
      <td>Contest Date</td>
      <td>

END;
// ----- END -----
         print "         <select name=\"cddate\">\n";
         for ($i = 1; $i <= 31; $i++) {
            $sel = ($i == $cddate) ? "selected=\"selected\"" : "";
            printf("            <option value=\"%02d\" $sel>%02d</option>\n", $i, $i);
         }
         print "         </select>\n";
         print "         <select name=\"cdmonth\">\n";
         for ($i = 0; $i < 12; $i++) {
            $sel = ($g_months[$i] == $cdmonth) ? "selected=\"selected\"" : "";
            print "            <option value=\"$g_months[$i]\" $sel>$g_months[$i]</option>\n";
         }
         print "         </select>\n";
         print "         <select name=\"cdyear\">\n";
         for ($i = 2016; $i <= 2020; $i++) {
            $sel = ($i == $cdyear) ? "selected=\"selected\"" : "";
            print "            <option value=\"$i\" $sel>$i</option>\n";
         }
         print "         </select>\n";
// ----- HTML -----
print <<<END
      </td>
   </tr>
   <tr>
      <td>Contest Start</td>
      <td>

END;
// ----- END -----
         print "         <select name=\"cdhour\">\n";
         for ($i = 0; $i <= 23; $i++) {
            $sel = ($i == $cdhour) ? "selected=\"selected\"" : "";
            printf("            <option value=\"%02d\" $sel>%02d</option>\n", $i, $i);
         }
         print "         </select> :\n";
         print "         <select name=\"cdminute\">\n";
         for ($i = 0; $i < 60; $i += 5) {
            $sel = ($i == $cdminute) ? "selected=\"selected\"" : "";
            printf("            <option value=\"%02d\" $sel>%02d</option>\n", $i, $i);
         }
         print "         </select>\n";
// ----- HTML -----
print <<<END
      </td>
   </tr>
   <tr>
      <td>Contest Length</td>
      <td>
         <input type="text"  name="clhours" size="5" value="$clhours" /> Hours&nbsp;
         <input type="text"  name="clminutes" size="3" value="$clminutes" /> Minutes
      </td>
   </tr>
   <tr>
      <td>Scoreboard Freeze</td>
      <td>
         <input type="text" name="freeze" size="2" value="$freeze" />
         Minutes prior to end of contest
      </td>
   </tr>
   <tr>
      <td>Show Problem Titles&nbsp;&nbsp;</td>
      <td>
         <input type="checkbox" name="showtitle" $showtitle />
         &nbsp;(prior to contest start)
      </td>
   </tr>
   <tr>
      <td><b>Problem Set Name</b></td>
      <td><input type="text" name="cname" size="30" value="$cname" /></td>
   </tr>
   </table> </div>
   <div class="col-2"> </div>  </div>
   </div>
   <br>
END;
// ----- END -----
?>

<table class="" style="table-layout: fixed; width: 100%">  <?php // table-responsive" style="overflow:hidden"> ?>
<thead>
<tr >
   <th width="6%">Initial</th>
   <th width="20%">Problem Name</th>
   <th width="8%">URL</th>
   <th width="17%">Statement</th>
   <th width="17%">Input (<i>filename</i>.in) </th>
   <th width="17%">Answer (<i>filename</i>.out) </th>
   <th width="10%">Prereq </th>
   <th width="6%">Time</th>
</tr>
</head>

<?php
   for ($i = 1; $i <= 10; $i++)
   {
      $line = explode(";", $problems[$i-1]);
      $name = htmlspecialchars(trim($line[0]));
      $url  = trim($line[1]);
      $prereq = trim($line[2]);
      $prereq = $prereq == '' ? '--' : $prereq;
      $tlimit = trim($line[3] ?? '1');

      if ($i % 2)    print "<tr bgcolor=\"#EDF3FE\">\n";
      else           print "<tr>\n";

      if ($i == 1)
      {
         $values = array("A", "1");
         print "   <td>&nbsp;Problem <select name=\"firstletter\">";
         foreach ($values as $value) {
            $sel = ($value == $firstletter) ? "selected=\"selected\"" : "";
            print "<option value=\"$value\" $sel>$value</option>";
         }
         print "</select>&nbsp;</td>\n";
      }
      else           print "   <td></td>\n";

      print "   <td align=\"center\"><input type=\"text\" class=\"form-control\" name=\"problem$i\" value=\"$name\" /></td>\n";
      print "   <td align=\"center\"><input type=\"text\" class=\"form-control\" name=\"problem$i-u\" value=\"$url\" /></td>\n";
      print "   <td><input style=\"max-width:200px\" class=\"form-control-file\" type=\"file\" name=\"problem$i-f\" /></td>\n";
      print "   <td><input style=\"max-width:200px\" class=\"form-control-file\" type=\"file\" name=\"input$i-f\"   /></td>\n";
      print "   <td><input style=\"max-width:200px\" class=\"form-control-file\" type=\"file\" name=\"output$i-f\"  /></td>\n";
      print "   <td align=\"center\"><input type=\"text\" class=\"form-control\" name=\"prereq$i\" value=\"$prereq\" /></td>\n";
      print "   <td align=\"center\"><input type=\"text\" class=\"form-control\" name=\"tlimit$i\" value=\"$tlimit\" /></td>\n";
      print "</tr>\n";
   }
?>
<tr bgcolor="#EEEEEE">
   <td colspan="3" align="right"><i>Upload a ZIP archive containing additional or all files:&nbsp;&nbsp;</i></td>
   <td><input type="file" name="archive" /></td>
</tr>
</table>
<p><i>Note: All uploaded files remain on the server, and files with the same
      name will overwrite existing files.</i>
<p><input type="submit" name="contest" value="Save Contest"/></p>
</form>

</div>

<!-- ------------------ TEAMS ------------------ -->
<hr>
<div align="center">

<p><b><big>Team Configuration</big></b></p>
<p><i>Note: Teams marked as "Guest" will be hidden from the main scoreboard.</i>
<?php
   if (isset($_SESSION["savedt"]))
   {
      print "<p><font color=\"green\">Team information saved.</font></p>\n";
      unset($_SESSION["savedt"]);
   }
?>

<form name="teams" method="post" action="jconfig.php">
<table border="1" width="900" cellspacing="0" cellpadding="2">
<tr bgcolor="#EEEEEE">
   <th width="120">Team ID</th>
   <th width="120">Password</th>
   <th width="60">Official</th>
   <th width="240">Team Name</th>
   <th>Members</th>
</tr>

<?php
   // print table with team information, values obtained from g_teams array
   reset($g_teams);
   for ($i = 1; $i <= $g_teamtablesize; $i++)
   {
      list($team, $password) = each($g_teams);
//      $official = in_array($team, $g_official) ? "checked=\"checked\"" : "";
      $name = $g_alias[$team];
      $members = $g_members[$team];
      $categories = array("Yes", "No", "Guest");
      $cvalues    = array(1, 0, -1);
      $official = 0;
      if (in_array($team, $g_official))   $official = 1;
      if (in_array($team, $g_invisible))  $official = -1;

      if ($i % 2) print "<tr bgcolor=\"#EDF3FE\">\n";
      else         print "<tr>\n";
      print "   <td align=\"center\"><input type=\"text\" name=\"team$i\" size=\"12\" value=\"$team\" /></td>\n";
      print "   <td align=\"center\"><input type=\"text\" name=\"team$i-p\" size=\"12\" value=\"$password\" /></td>\n";
//      print "   <td align=\"center\"><input type=\"checkbox\" name=\"team$i-o\" $official /></td>\n";
      print "   <td align=\"center\"><select name=\"team$i-o\" >\n";
      for ($j = 0; $j < 3; $j++) {
         $selected = ($official == $cvalues[$j]) ? "selected" : "";
         print "      <option $selected value=\"$cvalues[$j]\">$categories[$j]</option>\n";
      }
      print "   </select></td>\n";
      print "   <td align=\"center\"><input type=\"text\" name=\"team$i-n\" size=\"24\" value=\"$name\" /></td>\n";
      print "   <td align=\"center\"><input type=\"text\" name=\"team$i-m\" size=\"36\" value=\"$members\" /></td>\n";
      print "</tr>\n";
   }
?>

</table>
<p><input type="submit" name="teams" value="Save Teams"/></p>
</form>

</div>

<?php footer($contest->chost); ?>

</body>

</html>
