<?php
   // -----------------------------------------------------------------------

    function headerer($title){
        print "<title>".$title."</title>\n";
        print '<meta charset="utf-8" />
    <meta name="viewport" content="width=device-width, user-scalable=no, initial-scale=1.0, minimum-scale=1.0, maximum-scale=1.0" />
    <meta name="description" content="UCLA Coding Competition" />
    <meta name="author" content="" />
    <title>CodeSprint LA</title>
    <!-- Bootstrap core CSS-->
    <!-- Latest compiled and minified CSS -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css" integrity="sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm" crossorigin="anonymous">
    Custom
     <link rel="stylesheet" href="style.css" >

    ';
    #<!--main css-->
    #<link rel="stylesheet" href="static/css/home.css" />
    }

   function navigation($from)
   {
    print '

    <nav class="navbar navbar-expand-md navbar-dark fixed-top bg-dark">
      <a class="navbar-brand" href="#">CodeSprint</a>
      <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarsExampleDefault" aria-controls="navbarsExampleDefault" aria-expanded="false" aria-label="Toggle navigation">
        <span class="navbar-toggler-icon"></span>
      </button>

      <div class="collapse navbar-collapse" id="navbarsExampleDefault">
        <ul class="navbar-nav mr-auto">';

      if ($from != "index")
         print "<li class='nav-item'><a class='nav-link ' href='index.php'> contest </a></li>";
      else print "<li class='nav-item'><a class='nav-link active' href='#'> contest </a></li>";

      if ($from != "scores")
         print "<li class='nav-item'><a class='nav-link' href='scores.php'> scoreboard </a></li>";
      else print "<li class='nav-item'><a class='nav-link active' href='#'> scoreboard </a></li>";

      if ($from != "submit")
         print "<li class='nav-item'><a class='nav-link' href='submit.php'> submissions </a></li>";
      else print "<li class='nav-item'><a class='nav-link active' href='#'> submissions </a></li>";

      if ($from != "clarify")
         print "<li class='nav-item'><a class='nav-link' href='clarify.php'> clarifications </a></li>";
      else print "<li class='nav-item'><a class='nav-link active' href='#'> clarifications </a></li>";

      if ($from != "help")
         print "<li class='nav-item'><a class='nav-link' href='help.php'> help </a></li>";
      else print "<li class='nav-item'><a class='nav-link active' href='#'> help </a></li>";

      print '</ul>';
      print '<ul class="navbar-nav navbar-right">';
      // toggle between displaying "Log In" and "Log Out"
      if (empty($_SESSION["teamid"]))
      {
         if ($from != "login")
            print "<a class='nav-link' href='login.php'>log in</a>";
         else print "<a class='nav-link active' href='#'>log in</a>";
      }
      else
      {
         print "<a class='nav-link active' href='login.php'>log out</a>";
      }

      print '</ul>
      </div>
    </nav>';
   }

   function jnavigation($from)
   {
      print "<hr><div align=\"center\"><p>\n";
      print "[ ";

      if ($from != "judge")
         print "<a href=\"judge.php\">Judgements</a>";
      else print "Judgements";
      print " | ";

      if ($from != "jclarify")
         print "<a href=\"jclarify.php\">Clarifications</a>";
      else print "Clarifications";
      print " | ";

      if ($from != "jscores")
         print "<a href=\"jscores.php\">Scoreboard</a>";
      else print "Scoreboard";
      print " | ";

      if ($from != "jconfig")
         print "<a href=\"jconfig.php\">Configuration</a>";
      else print "Configuration";
      print " | ";

      print "<a href=\"..\" target=\"new\">Contest Page</a>";

      print " ]\n";
      print "</p></div>\n";
   }

   function footer($email)
   {
    print '<hr/>';
      print '<footer class="container py-5">
      <div class="row">
        <div class="col-12 col-md">
          <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="d-block mb-2"><circle cx="12" cy="12" r="10"></circle><line x1="14.31" y1="8" x2="20.05" y2="17.94"></line><line x1="9.69" y1="8" x2="21.17" y2="8"></line><line x1="7.38" y1="12" x2="13.12" y2="2.06"></line><line x1="9.69" y1="16" x2="3.95" y2="6.06"></line><line x1="14.31" y1="16" x2="2.83" y2="16"></line><line x1="16.62" y1="12" x2="10.88" y2="21.94"></line></svg>
          <p class="d-block mb-3 text-muted">UCLA CodeSprint 2018<br/>
            Hosted by ACM - ICPC
    </div>

    <div class="col-12 col-md">
          <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="d-block mb-2"><circle cx="12" cy="12" r="10"></circle><line x1="14.31" y1="8" x2="20.05" y2="17.94"></line><line x1="9.69" y1="8" x2="21.17" y2="8"></line><line x1="7.38" y1="12" x2="13.12" y2="2.06"></line><line x1="9.69" y1="16" x2="3.95" y2="6.06"></line><line x1="14.31" y1="16" x2="2.83" y2="16"></line><line x1="16.62" y1="12" x2="10.88" y2="21.94"></line></svg>
          <p class="d-block mb-3 text-muted">
          Ultra Cool Programming<br/>
           Contest Control Centre v1.8<br/>
        Copyright (c) 2005-2010<br/>
         By Sonny Chan</p>
    </div>

        <div class="col-12 col-md">
          <h5>Questions?</h5>
          <p class="text-muted">For your questions, comments, and issues...<br/>
            please contact your host today at<br>
            </p>
            <a class="text-muted" href="mailto:'.$email.'">'.$email.'</a>
      </div>
    </footer>';
   }

   // -----------------------------------------------------------------------

   function contesttime($cdate, $ctime)
   {
      $dstamp = strtotime($cdate);
      list($cstart, $clhours, $clminutes) = sscanf($ctime, "%s + %d:%d");
      $sstamp = strtotime($cstart, $dstamp);
      $estamp = $sstamp + $clhours*60*60 + $clminutes*60;
      return array($sstamp, $estamp);
   }

   function intervaltostr($interval)
   {
      $seconds = $interval % 60; $interval /= 60;
      $minutes = $interval % 60; $interval /= 60;
      $hours = $interval;
      $istr = sprintf("%02d:%02d", $hours, $minutes);
      return $istr;
   }

   // -----------------------------------------------------------------------

   class Contest
   {
      var $cname;
      var $cdate;
      var $ctime;
      var $chost;

      var $tstart;
      var $tend;
      var $tnow;
      var $tfreeze;

      var $firstletter;
      var $showtitles;

      var $pletters = array();
      var $pnames = array();
      var $purls = array();

      var $okay;

      function Contest($problemfile, $problempath)
      {
         // Don't know why this include is necessary... remove if possible
         include("config.php");

         $this->tnow = time();

         if ($fp = fopen($problemfile, "r"))
         {
            flock($fp, LOCK_SH);

            // read page title and contest host contact
            fgets($fp);
            $this->chost = trim(fgets($fp));

            // read contest date and time from file
            $datestr = trim(fgets($fp));
            $timestr = trim(fgets($fp));

            // convert contest date and time into time stamps and strings
            list($this->tstart, $this->tend) = contesttime($datestr, $timestr);
            $this->cdate = date("l, F d, Y", $this->tstart);
            $this->ctime = date("H:i", $this->tstart) . " to " . date("H:i T", $this->tend);

            // read scoreboard freeze, first letter, and show titles
            list($freeze, $this->firstletter, $showtitles) = explode(";", trim(fgets($fp)));
            $this->tfreeze = $this->tend - $freeze*60;
            $this->showtitles = $showtitles ? True : False;

            // read problem set name
            $this->cname = trim(fgets($fp));

            // read problem names and URLs into their arrays
            $letter = $this->firstletter;
            while ($line = fgets($fp))
            {
               $line = explode(";", $line);
               $ptitle = ($this->showtitles || $this->tnow >= $this->tstart) ?
                         htmlspecialchars(trim($line[0])) : "?????";
               $name = "$letter - " . $ptitle;
               $url  = $problempath . trim($line[1]);

               $this->pletters[] = $letter;
               $this->pnames[$letter] = $name;
               $this->purls[$letter] = $url;

               ++$letter;
            }

            fclose($fp);
            $this->okay = True;
         }
         else
         {
            print "Cannot open $problemfile for data!";
            $this->okay = False;
         }
      }

      function problemlink($letter)
      {
         $name = $this->pnames[$letter];
         $url = $this->purls[$letter];
         if ($this->tnow >= $this->tstart)
            return "<a href=\"$url\">$name</a>";
         else
            return $name;
      }

      function problemlonglink($letter)
      {
         $name = $this->pnames[$letter];
         $url = $this->purls[$letter];
         if ($this->tnow >= $this->tstart)
            return "<a href=\"$url\">Problem $name</a>";
         else
            return "Problem " . $name;
      }

      function problemshortlink($letter)
      {
         $url = $this->purls[$letter];
         if ($this->tnow >= $this->tstart)
            return "<a href=\"$url\">$letter</a>";
         else
            return $letter;
      }

      function jproblemlink($letter)
      {
         $name = $this->pnames[$letter];
         $url = $this->purls[$letter];
         if ($this->tnow >= $this->tstart)
            return "<a href=\"../$url\">$name</a>";
         else
            return $name;
      }

      function jproblemshortlink($letter)
      {
         $url = $this->purls[$letter];
         if ($this->tnow >= $this->tstart)
            return "<a href=\"../$url\">$letter</a>";
         else
            return $letter;
      }
   }

   // -----------------------------------------------------------------------

   class Run
   {
      var $time;
      var $team;
      var $problem;
      var $language;
      var $file;
      var $verdict;

      function Run($key)
      {
         list($this->time, $this->team, $this->problem, $this->language, $this->file) = explode(",", trim($key));
         $this->verdict = "U";
      }

      function key()
      {
         return "$this->time,$this->team,$this->problem,$this->language,$this->file";
      }

      function judgement()
      {
         return "$this->time,$this->team,$this->problem,$this->language,$this->file;$this->verdict\n";
      }
   }

   // -----------------------------------------------------------------------

   class TeamScore
   {
      var $name;
      var $id;
      var $solved = array();
      var $attime = array();
      var $booboo = array();
      var $total = 0;
      var $penalty = 0;

      function TeamScore($team, $id = "", $pv = [])
      {
         $this->name = $team;
         $this->id = $id;
         $this->pv = $pv;
      }

      // report the result of a judgement to this team's record
      // assumes all reports are done in chronological order
      function report($problem, $time, $verdict)
      {
         if (in_array($problem, $this->solved))
            return;

         switch ($verdict)
         {
            // unjuged or submission error, ignore
            case "U":
            case "E":
               break;
            // accepted, add penalty points
            case "A":
               if (!in_array($problem, $this->solved))  {
                   $this->total += $this->pv[$problem];
                   $this->solved[] = $problem;
               }
               $this->attime[$problem] = $time;
               // trigger_error("Teamscore receives problem " . $problem, E_USER_WARNING);
               // NEW_EDIT: DON"T PENALIZE BY WAs AT ALL
               $this->penalty += $this->attime[$problem]; // + $this->booboo[$problem] * 20;
               break;
            // default - assume it's wrong
            default:
               $this->booboo[$problem] += 1;
               break;
         }
      }

      function problemstat($problem)
      {
         $stat = "&nbsp;";

         if (in_array($problem, $this->solved))
         {
            //$stat = $this->attime[$problem];
            $stat = $this->pv[$problem];
            // trigger_error("g_pv for " . $problem . " is" . $stat, E_USER_WARNING);
            //if (array_key_exists($problem, $this->booboo))
            $seconds = $this->attime[$problem];
            $minutes = floor($seconds / 60);
            $seconds = $seconds - $minutes * 60;
            if ($seconds < 10) $seconds = "0" . $seconds;
            $stat = $stat . " (" . $minutes . ":" . $seconds .")";
         }
         else if (array_key_exists($problem, $this->booboo))
         {
            $stat = "(-" . $this->booboo[$problem] . ")";
         }
         else {
             $stat = "0";
         }

         return $stat;
      }

      function key()
      {
         return sprintf("%03d%05d%s", 999 - $this->total, $this->penalty, $this->name);
      }
   }

   // -----------------------------------------------------------------------

   class Clarification
   {
      var $id;
      var $from;
      var $problem;
      var $responded = False;
      var $fresh = False;
      var $question;
      var $answer;

      function Clarification($team, $p, $q)
      {
         $this->id = time();
         $this->from = $team;
         $this->problem = $p;
         $this->question = $q;
      }

      function read($fp)
      {
         $stamp = (int) trim(fgets($fp));
         $team = trim(fgets($fp));
         $p = trim(fgets($fp));
         $r = (boolean) trim(fgets($fp));
         $q = "";
         $a = "";
         if (trim(fgets($fp)) == "{")
            for ($line = fgets($fp); trim($line) != "}"; $line = fgets($fp))
               $q = $q . $line;
         if ($r && trim(fgets($fp)) == "{")
            for ($line = fgets($fp); trim($line) != "}"; $line = fgets($fp))
               $a = $a . $line;

         $c = new Clarification($team, $p, $q);
         $c->id = $stamp;
         $c->responded = $r;
         $c->answer = $a;

         return $c;
      }

      function write($fp)
      {
         if ($fp)
         {
            fputs($fp, $this->id . "\n");
            fputs($fp, $this->from . "\n");
            fputs($fp, $this->problem . "\n");
            fputs($fp, $this->responded . "\n");
            fputs($fp, "{\n" . $this->question . "\n}\n");
            if ($this->responded)
               fputs($fp, "{\n" . $this->answer . "\n}\n");
         }
      }

   }

       // -----------------------------------------------------------------------
?>
