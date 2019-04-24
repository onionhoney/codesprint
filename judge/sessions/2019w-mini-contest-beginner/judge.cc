#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <locale>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <unistd.h>

using namespace std;

const char infofile[] = "config.txt";
map<string, vector<string> > input, output;
map<string, int> timelimit;
map<string, string> verifier;   // verifier is program that should behave like diff
map<string, bool> interact;
map<int, char> verdict;
map<int, string> vname;

string strip(string s) {
    int i = 0, j = s.size() - 1; 
    while (i <= j && isblank(s[i])) i++;
    while (j >= 0 && isblank(s[j])) j--;
    if (i > j) return "";
    return s.substr(i, j - i + 1);
}

string join(vector<string>& v, char delim=',') {
    std::stringstream ss;
    for(size_t i = 0; i < v.size(); ++i)
    {
          if(i != 0)
                  ss << delim;
            ss << v[i];
    }
    std::string s = ss.str();
    return s;
}

vector<string> split(string s, char delim=';') {
    string accum = "";
    vector<string> result;

    assert(strip("  st ") == "st");
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == delim) {
            accum = strip(accum);
            result.push_back(accum);
            accum = "";
        } else {
            accum += s[i];
        }
    }
    accum = strip(accum);
    if (accum != "") result.push_back(accum);
    return result;
}

void init()
{
    string problem, iname, oname, check, twoway;
    const string prefix = "data/";

    ifstream in(infofile);
    string line;
    for (int i = 0; i < 6; i++) getline(in, line);

    vector<string> test = split("p;s;et;");
    assert(test == vector<string>({"p", "s", "et"}));

    while (getline(in, line)) {
        vector<string> s = split(line);
        problem = s[1];
        iname = prefix + problem + ".in";
        oname = prefix + problem + ".out";
        int limit = s.size() < 4 ? 1 : stoi(s[3]);
        input[problem].push_back(iname);
        output[problem].push_back(oname);
        timelimit[problem] = limit;
    } 
        
    /*
        if (iss >> check) verifier[problem] = "./" + check;
        if (iss >> twoway) interact[problem] = true;
    */
    in.close();

    verdict[0] = 'A';   vname[0] = "Accepted";
    verdict[1] = 'C';   vname[1] = "Compile Error";
    verdict[2] = 'T';   vname[2] = "Time Limit Exceeded";
    verdict[3] = 'R';   vname[3] = "Run-Time Error";
    verdict[4] = 'P';   vname[4] = "Presentation Error";
    verdict[5] = 'W';   vname[5] = "Wrong Answer";
    verdict[6] = 'U';   vname[6] = "Unjudged";
}

void judge(bool interactive = true)
{
    map<string, char> judged;
    set<string> submit;
    map<string, char> judging;
    map<string, set<string> > solved;

    ifstream jin("judgements.txt");
    string s;
    while (getline(jin, s)) {
        string key;


        istringstream iss(s);
        getline(iss, key, ';');
        char state;
        iss.get(state);

        judged[key] = state;
    }
    jin.close();

    ifstream sin("submissions.txt");
    while (getline(sin, s)) {
        if (judged.find(s) == judged.end() || judged[s] == 'U') {
            cout << "not yet processed or processed but unjudged" << endl;
            submit.insert(s);
        }
    }
    sin.close();

    ifstream solvedin("solved.txt");
    while (getline(solvedin, s)) {
        stringstream teamline(s);
        string teamname;
        string prob;
        getline( teamline, teamname, ';');
        while(teamline.good())
        {
            getline( teamline, prob, ',');
            solved[teamname].insert(prob);
        }
    }
    solvedin.close();


    for (set<string>::iterator it = submit.begin(); it != submit.end(); ++it)
    {
        string time, team, problem, language, file;
        istringstream iss(*it);
        getline(iss, time, ',');
        getline(iss, team, ',');
        getline(iss, problem, ',');
        getline(iss, language, ',');
        getline(iss, file);

        int tests = input[problem].size();

        int code = (tests > 0) ? 0 : 6;
        for (int i = 0; i < tests && code == 0; ++i)
        {
            ostringstream oss;
            if (interact[problem]) {
                oss << "./grade_interactive.pl " << team << '/' << file << ' '
                    << verifier[problem] << ' ' << input[problem][i] << ' '
                    << timelimit[problem];
            }
            else {
                oss << "./grade_standalone.pl " << team << '/' << file << ' '
                    << input[problem][i] << ' ' << output[problem][i] << ' '
                    << timelimit[problem] << ' ' << verifier[problem];
            }
            code = system(oss.str().c_str());
            code = WEXITSTATUS(code);

        }

        if (interactive)
        {
            char v;
            cout << "Accept verdict \"" << vname[code] << "\" for problem " << problem
                 << " submitted by " << team << "? (y/n) ";
            cin >> v;
            if (v == 'y')
                judging[*it] = verdict[code];
            else {
                cout << "Enter new verdict: (A/R/T/W/P/C/E/U) ";
                cin >> v;
                judging[*it] = toupper(v);
            }
        }
        else
        {
            cout << "Verdict for " << *it << " is: " << verdict[code] << endl;
            judging[*it] = verdict[code];
        }
        if (verdict[code] == 'A')
            solved[team].insert(problem);

        ofstream sout("solved.txt");
        for (auto p : solved) {
            vector<string> haha(p.second.begin(), p.second.end());
            sout << p.first << ";" << join(haha) << endl;
            sout.flush();
        }
        cout << "Haha updated solve.txt" << endl;
        sout.close();
    }


    ofstream jout("judgements.txt", ios::app);
    for (map<string, char>::iterator it = judging.begin(); it != judging.end(); ++it) {
        jout << it->first << ';' << it->second << endl;
    }
    jout.close();
}

int main(int argc, char *argv[])
{
    init();

    // if argc == 1 then run interactive
    if (argc == 1)
    {
        cout << "------------------------------------------------------------" << endl;
        cout << "Judging all new submissions in INTERACTIVE mode." << endl;
        cout << "(for autojudge, use judge [-auto <seconds>])" << endl;
        cout << "------------------------------------------------------------" << endl;
        judge();
    }
    else
    {
        if (argc == 3 && string(argv[1]) == "-auto")
        {
            int interval = min(max(5, atoi(argv[2])), 600);
            cout << "------------------------------------------------------------" << endl;
            cout << "Starting AUTOJUDGE with time interval of " << interval << " seconds" << endl;
            cout << "------------------------------------------------------------" << endl;

            char buffer[32];
            for (int round = 1;; ++round)
            {
                const time_t t = time(0);
                ctime_r(&t, buffer);
                buffer[24] = 0;
                cout << '[' << buffer << "] Running judge round " << round << endl;

                judge(false);
                sleep(interval);
            }
        }
        else
            cout << "USAGE:  judge [-auto <seconds>]" << endl;
    }

    return 0;
}
