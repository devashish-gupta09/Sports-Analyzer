#include <bits/stdc++.h>
using namespace std;

//Base class of the program
class Sports
{
protected:
public:
    //Components of Sports common for all 3 sports.
    string First_name;
    string Last_name;
    int Age;
    string Team;
    string Country;
    int Win;
    int Lost;
    int No_of_matches;

    Sports() //Default Constructor
    {
        First_name = "";
        Last_name = "";
        Age = 0;
        Team = "";
        Country = "";
        Win = 0;
        Lost = 0;
        No_of_matches = 0;
    }

    //Parameterized Constructor
    Sports(string first_name, string last_name, int age, string team, string country, int win, int lost, int no_of_matches)
    {
        First_name = first_name;
        Last_name = last_name;
        Age = age;
        Team = team;
        Country = country;
        Win = win;
        Lost = lost;
        No_of_matches = no_of_matches;
    }

    ~Sports() {} //Destructor

    void Main_Display()
    {
        cout << "                                      **********************************" << endl;
        cout << "                                      WELCOME TO SPORTS ANALYZER PROGRAM" << endl;
        cout << "                                      **********************************" << endl
             << endl
             << endl;
        cout << "                                      ";
        system("pause");
        system("cls");

        cout << "                                      **********************************" << endl;
        cout << "                                      WELCOME TO SPORTS ANALYZER PROGRAM" << endl;
        cout << "                                      **********************************" << endl
             << endl
             << endl;

        cout << "                                      Please Choose the Sports by pressing the number next to it : " << endl
             << endl;
        cout << "                                      1) Football" << endl;
        cout << "                                      2) Basketball" << endl;
        cout << "                                      3) Cricket" << endl;
        cout << "                                      0) To exit the program " << endl
             << endl;
        cout << "                                      Enter your choice: ";
    }
};

//Base class for football ---> Inherited from class "Sports"
class Football : public Sports
{
protected:
public:
    string Position;
    int Pass_Accuracy;
    int Red_card;
    int Draw;

    Football() //Default Constructor for Football class
    {
        Position = "";
        Pass_Accuracy = 0;
        Red_card = 0;
        Draw = 0;
    }

    //Parameterized Constructor for Football class
    Football(string first_name, string last_name, int age, string team, string country, int win, int lost, int no_of_matches, string position, int pass_accuracy, int red_card, int draw) : Sports(first_name, last_name, age, team, country, win, lost, no_of_matches)
    {
        Position = position;
        Pass_Accuracy = pass_accuracy;
        Red_card = red_card;
        Draw = draw;
    }

    ~Football() {} //Deconstructor for Football class

    void Display_content_f()
    {
        cout << "                                      **********************************" << endl;
        cout << "                                      WELCOME TO SPORTS ANALYZER PROGRAM" << endl;
        cout << "                                      **********************************" << endl
             << endl
             << endl;
        cout << "                                      >>>>>> Welcome to Football <<<<<<" << endl
             << endl;
        cout << "                                      1. View Teams " << endl;
        cout << "                                      2. View Players " << endl;
        cout << "                                      3. Stats " << endl;
        cout << "                                      4. Standings " << endl;
        cout << "                                      5. Return to Main Menu" << endl;
        cout << "                                      0. EXIT" << endl
             << endl;
        cout << "                                      Enter your choice: ";
    }

    void Team_display_f() //For diplaying the teams of football
    {
        fstream team_f("team_f.txt");
        string f;
        if (!team_f)
            cout << "Error" << endl;
        else
        {
            while (!team_f.eof())
            {
                getline(team_f, f);
                cout << f << endl;
            }
        }
    }

    void Standings_display_f() //For displaying the standings of football
    {
        fstream standings_f("standings_f.txt");
        string f;
        if (!standings_f)
            cout << "Error" << endl;
        else
        {
            while (!standings_f.eof())
            {
                getline(standings_f, f);
                cout << f << endl;
            }
        }
    }
};
//Attack class (Inherited from Football class --> Will contain all the components of Football as well as its parent class Sports)
class Attack : public Football
{
protected:
public:
    int Goals;
    float Shot_accuracy;
    int Assist;

    Attack() // Default Constructor for Attack class
    {
        Goals = 0;
        Shot_accuracy = 0;
        Assist = 0;
    }

    // Parameterized Constructor for Attack class
    Attack(string first_name, string last_name, int age, string team, string country, int win, int lost, string position, int no_of_matches, int assist, int pass_accuracy, int red_card, int draw, int goals, float shot_accurracy) : Football(first_name, last_name, age, team, country, win, lost, no_of_matches, position, pass_accuracy, red_card, draw)
    {
        Assist = assist;
        Goals = goals;
        Shot_accuracy = shot_accurracy;
    }

    ~Attack() {} // Destructor for Attack class

    void Display_stats_f_a(Attack *A)
    {
        fstream stats_f_a("attack.txt");
        int id[60];
        int _id = 1;
        for (int i = 0; i < 60; i++)
        {
            id[i] = _id;
            _id++;
        }

        stats_f_a.seekg(0);
        for (int i = 0; i < 58; i++)
        {
            stats_f_a >> A[i].First_name >> A[i].Last_name >> A[i].Position >> A[i].Age >> A[i].Team >> A[i].Country >> A[i].No_of_matches >> A[i].Goals >> A[i].Shot_accuracy >> A[i].Assist >> A[i].Pass_Accuracy >> A[i].Red_card;
        }
        cout << "SNO F.Name    L.Name        Pos  AGE TEAM               COUNTRY      App  Goals S.Accu Ass P.Accu RCd" << endl
             << endl
             << endl;
        for (int i = 0; i < 58; i++)
        {
            cout << left << setw(4) << id[i] << setw(10) << A[i].First_name << setw(14) << A[i].Last_name << setw(5) << A[i].Position << setw(4) << A[i].Age << setw(19) << A[i].Team << setw(13) << A[i].Country << setw(5) << A[i].No_of_matches << setw(6) << A[i].Goals << setw(7) << A[i].Shot_accuracy << setw(4) << A[i].Assist << setw(7) << A[i].Pass_Accuracy << setw(3) << A[i].Red_card << endl;
            cout << "-----------------------------------------------------------------------------------------------------" << endl;
        }
    }

    void Search_player_f_a(Attack *A, string name)
    {
        fstream psearch_a("attack.txt");
        int id[60];
        int _id = 1;
        for (int i = 0; i < 60; i++)
        {
            id[i] = _id;
            _id++;
        }
        psearch_a.seekg(0);

        for (int i = 0; i < 58; i++)
        {
            psearch_a >> A[i].First_name >> A[i].Last_name >> A[i].Position >> A[i].Age >> A[i].Team >> A[i].Country >> A[i].No_of_matches >> A[i].Goals >> A[i].Shot_accuracy >> A[i].Assist >> A[i].Pass_Accuracy >> A[i].Red_card;
        }

        int check = 0;

        for (int i = 0; i < 58; i++)
        {
            if (name == A[i].First_name || name == A[i].Last_name)
            {
                check = 1;
            }
        }

        if (check == 1)
        {
            cout << "SNO F.Name    L.Name        Pos  AGE TEAM                  COUNTRY      App  Goals S.Accu Ass P.Accu RCd" << endl
                 << endl
                 << endl;
        }
        else
        {
            cout << "This player does not exist" << endl
                 << endl;
        }

        for (int i = 0; i < 58; i++)
        {
            if (name == A[i].First_name || name == A[i].Last_name)
            {
                cout << left << setw(4) << id[i] << setw(10) << A[i].First_name << setw(14) << A[i].Last_name << setw(5) << A[i].Position << setw(4) << A[i].Age << setw(22) << A[i].Team << setw(13) << A[i].Country << setw(5) << A[i].No_of_matches << setw(6) << A[i].Goals << setw(7) << A[i].Shot_accuracy << setw(4) << A[i].Assist << setw(7) << A[i].Pass_Accuracy << setw(3) << A[i].Red_card << endl;
                cout << "---------------------------------------------------------------------------------------------------------" << endl;
            }
        }
    }

    void Player_display_f_a(Attack *A)
    {
        fstream player_f_a("attack.txt");

        int id[60];
        int _id = 1;
        for (int i = 0; i < 60; i++)
        {
            id[i] = _id;
            _id++;
        }
        player_f_a.seekg(0);

        for (int i = 0; i < 60; i++)
        {
            player_f_a >> A[i].First_name >> A[i].Last_name >> A[i].Position >> A[i].Age >> A[i].Team >> A[i].Country >> A[i].No_of_matches >> A[i].Goals >> A[i].Shot_accuracy >> A[i].Assist >> A[i].Pass_Accuracy >> A[i].Red_card;
        }
        cout << "FORWARD : " << endl
             << endl;
        cout << "SNO F.Name    L.Name        Pos  AGE TEAM               COUNTRY" << endl
             << endl;
        for (int i = 0; i < 45; i++)
        {
            cout << left << setw(4) << id[i] << setw(10) << A[i].First_name << setw(14) << A[i].Last_name << setw(5) << A[i].Position << setw(4) << A[i].Age << setw(19) << A[i].Team << setw(13) << A[i].Country << endl;
            cout << "----------------------------------------------------------------------" << endl;
        }
        cout << endl;
    }
};
//Midfield class (Inherited from Football class --> Will contain all the components of Football as well as its parent class Sports)
class MidField : public Football
{
protected:
public:
    int Goals;
    float Shot_accuracy;
    int Assist;

    MidField() //Default Constructor for Midfield class
    {
        Goals = 0;
        Shot_accuracy = 0;
    }

    //Parameterized Constructor for Midfield class
    MidField(string first_name, string last_name, int age, string team, string country, int win, int lost, string position, int no_of_matches, int assist, int pass_accuracy, int red_card, int draw, int goals, float shot_accurracy) : Football(first_name, last_name, age, team, country, win, lost, no_of_matches, position, pass_accuracy, red_card, draw)
    {
        Goals = goals;
        Shot_accuracy = shot_accurracy;
        Assist = assist;
    }

    ~MidField() {} //Destructor for Midfield class

    void Display_stats_f_m(MidField *Mf)
    {
        fstream stats_f_m("midfield.txt");
        int id[120];
        int _id = 1;
        for (int i = 0; i < 120; i++)
        {
            id[i] = _id;
            _id++;
        }

        stats_f_m.seekg(0);
        for (int i = 0; i < 111; i++)
        {
            stats_f_m >> Mf[i].First_name >> Mf[i].Last_name >> Mf[i].Position >> Mf[i].Age >> Mf[i].Team >> Mf[i].Country >> Mf[i].No_of_matches >> Mf[i].Goals >> Mf[i].Shot_accuracy >> Mf[i].Assist >> Mf[i].Pass_Accuracy >> Mf[i].Red_card;
        }
        cout << "SNO F.Name    L.Name        Pos  AGE TEAM                  COUNTRY      App  Goals S.Accu Ass P.Accu RCd" << endl
             << endl
             << endl;
        for (int i = 0; i < 111; i++)
        {
            cout << left << setw(4) << id[i] << setw(10) << Mf[i].First_name << setw(14) << Mf[i].Last_name << setw(5) << Mf[i].Position << setw(4) << Mf[i].Age << setw(22) << Mf[i].Team << setw(13) << Mf[i].Country << setw(5) << Mf[i].No_of_matches << setw(6) << Mf[i].Goals << setw(7) << Mf[i].Shot_accuracy << setw(4) << Mf[i].Assist << setw(7) << Mf[i].Pass_Accuracy << setw(3) << Mf[i].Red_card << endl;
            cout << "--------------------------------------------------------------------------------------------------------" << endl;
        }
    }

    void Search_player_f_m(MidField *Mf, string name)
    {
        fstream psearch_m("midfield.txt");
        int id[120];
        int _id = 1;
        for (int i = 0; i < 120; i++)
        {
            id[i] = _id;
            _id++;
        }
        psearch_m.seekg(0);
        for (int i = 0; i < 111; i++)
        {
            psearch_m >> Mf[i].First_name >> Mf[i].Last_name >> Mf[i].Position >> Mf[i].Age >> Mf[i].Team >> Mf[i].Country >> Mf[i].No_of_matches >> Mf[i].Goals >> Mf[i].Shot_accuracy >> Mf[i].Assist >> Mf[i].Pass_Accuracy >> Mf[i].Red_card;
        }

        int check = 0;

        for (int i = 0; i < 111; i++)
        {
            if (name == Mf[i].First_name || name == Mf[i].Last_name)
            {
                check = 1;
            }
        }

        if (check == 1)
        {
            cout << "SNO F.Name    L.Name        Pos  AGE TEAM                  COUNTRY      App  Goals S.Accu Ass P.Accu RCd" << endl
                 << endl
                 << endl;
        }
        else
        {
            cout << "This player does not exist" << endl
                 << endl;
        }

        for (int i = 0; i < 111; i++)
        {
            if (name == Mf[i].First_name || name == Mf[i].Last_name)
            {
                cout << left << setw(4) << id[i] << setw(10) << Mf[i].First_name << setw(14) << Mf[i].Last_name << setw(5) << Mf[i].Position << setw(4) << Mf[i].Age << setw(22) << Mf[i].Team << setw(13) << Mf[i].Country << setw(5) << Mf[i].No_of_matches << setw(6) << Mf[i].Goals << setw(7) << Mf[i].Shot_accuracy << setw(4) << Mf[i].Assist << setw(7) << Mf[i].Pass_Accuracy << setw(3) << Mf[i].Red_card << endl;
                cout << "--------------------------------------------------------------------------------------------------------" << endl;
            }
        }
    }

    void Player_display_f_m(MidField *Mf)
    {
        fstream player_f_m("midfield.txt");

        int id[120];
        int _id = 1;
        for (int i = 0; i < 120; i++)
        {
            id[i] = _id;
            _id++;
        }
        player_f_m.seekg(0);
        for (int i = 0; i < 111; i++)
        {
            player_f_m >> Mf[i].First_name >> Mf[i].Last_name >> Mf[i].Position >> Mf[i].Age >> Mf[i].Team >> Mf[i].Country >> Mf[i].No_of_matches >> Mf[i].Goals >> Mf[i].Shot_accuracy >> Mf[i].Assist >> Mf[i].Pass_Accuracy >> Mf[i].Red_card;
        }
        cout << "MID-FIELD : " << endl
             << endl;
        cout << "SNO F.Name    L.Name        Pos  AGE TEAM                  COUNTRY" << endl
             << endl;
        for (int i = 0; i < 111; i++)
        {
            cout << left << setw(4) << id[i] << setw(10) << Mf[i].First_name << setw(14) << Mf[i].Last_name << setw(5) << Mf[i].Position << setw(4) << Mf[i].Age << setw(22) << Mf[i].Team << setw(13) << Mf[i].Country << endl;
            cout << "-----------------------------------------------------------------------" << endl;
        }
        cout << endl;
    }
};
//Defence class (Inherited from Football class --> Will contain all the components of Football as well as its parent class Sports)
class Defence : public Football
{
protected:
public:
    int Goals;
    int Tackles_won;
    int Clearance;
    int Blocked_shots;
    int Assist;

    Defence() //Default constructor for Defence class
    {
        Goals = 0;
        Tackles_won = 0;
        Clearance = 0;
        Blocked_shots = 0;
        Assist = 0;
    }

    //Parameterized Constructor for Defence class
    Defence(string first_name, string last_name, int age, string team, string country, int win, int lost, string position, int no_of_matches, int assist, int pass_accuracy, int red_card, int draw, int goals, int tackles_won, int clearance, int blocked_shots) : Football(first_name, last_name, age, team, country, win, lost, no_of_matches, position, pass_accuracy, red_card, draw)
    {
        Goals = goals;
        Tackles_won = tackles_won;
        Clearance = clearance;
        Blocked_shots = blocked_shots;
        Assist = assist;
    }

    ~Defence() {} //Destructor for Defence class

    void Display_stats_f_d(Defence *D)
    {
        fstream stats_f_d("DEFENDERS.txt");
        if (!stats_f_d)
            cout << "Error opening this file!!" << endl;

        int id[120];
        int _id = 1;
        for (int i = 0; i < 120; i++)
        {
            id[i] = _id;
            _id++;
        }

        stats_f_d.seekg(0);
        for (int i = 0; i < 107; i++)
        {
            stats_f_d >> D[i].First_name >> D[i].Last_name >> D[i].Position >> D[i].Age >> D[i].Team >> D[i].Country >> D[i].No_of_matches >> D[i].Tackles_won >> D[i].Clearance >> D[i].Blocked_shots >> D[i].Red_card >> D[i].Goals >> D[i].Pass_Accuracy;
        }
        cout << "SNO F.NAME    L.NAME        POS  AGE TEAM                  COUNTRY      APP  TACKLE CLEARANCE BLK.SHOT RC Goals P.ACC" << endl
             << endl
             << endl;
        for (int i = 0; i < 107; i++)
        {
            cout << left << setw(4) << id[i] << setw(10) << D[i].First_name << setw(14) << D[i].Last_name << setw(5) << D[i].Position << setw(4) << D[i].Age << setw(22) << D[i].Team << setw(13) << D[i].Country << setw(5) << D[i].No_of_matches << setw(7) << D[i].Tackles_won << setw(10) << D[i].Clearance << setw(9) << D[i].Blocked_shots << setw(3) << D[i].Red_card << setw(6) << D[i].Goals << setw(7) << D[i].Pass_Accuracy << endl;
            cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
        }
    }

    void Search_player_f_d(Defence *D, string name)
    {
        fstream psearch_d("DEFENDERS.txt");
        if (!psearch_d)
            cout << "Error opening this file!!" << endl;
        int id[120];
        int _id = 1;
        for (int i = 0; i < 120; i++)
        {
            id[i] = _id;
            _id++;
        }
        psearch_d.seekg(0);
        for (int i = 0; i < 107; i++)
        {
            psearch_d >> D[i].First_name >> D[i].Last_name >> D[i].Position >> D[i].Age >> D[i].Team >> D[i].Country >> D[i].No_of_matches >> D[i].Tackles_won >> D[i].Clearance >> D[i].Blocked_shots >> D[i].Red_card >> D[i].Goals >> D[i].Pass_Accuracy;
        }

        int check = 0;

        for (int i = 0; i < 107; i++)
        {
            if (name == D[i].First_name || name == D[i].Last_name)
            {
                check = 1;
            }
        }

        if (check == 1)
        {
            cout << "F.NAME    L.NAME        POS  AGE TEAM                  COUNTRY      APP  TACKLE CLEARANCE BLK.SHOT RC Goals P.ACC" << endl
                 << endl
                 << endl;
        }
        else
        {
            cout << "This player does not exist" << endl
                 << endl;
        }

        for (int i = 0; i < 107; i++)
        {
            if (name == D[i].First_name || name == D[i].Last_name)
            {
                cout << left << setw(10) << D[i].First_name << setw(14) << D[i].Last_name << setw(5) << D[i].Position << setw(4) << D[i].Age << setw(22) << D[i].Team << setw(13) << D[i].Country << setw(5) << D[i].No_of_matches << setw(7) << D[i].Tackles_won << setw(10) << D[i].Clearance << setw(9) << D[i].Blocked_shots << setw(3) << D[i].Red_card << setw(6) << D[i].Goals << setw(7) << D[i].Pass_Accuracy << endl;
                cout << "------------------------------------------------------------------------------------------------------------------" << endl;
            }
        }
    }

    void Player_display_f_d(Defence *D)
    {
        fstream player_f_d("DEFENDERS.txt");

        int id[120];
        int _id = 1;
        for (int i = 0; i < 120; i++)
        {
            id[i] = _id;
            _id++;
        }
        player_f_d.seekg(0);
        for (int i = 0; i < 107; i++)
        {
            player_f_d >> D[i].First_name >> D[i].Last_name >> D[i].Position >> D[i].Age >> D[i].Team >> D[i].Country >> D[i].No_of_matches >> D[i].Tackles_won >> D[i].Clearance >> D[i].Blocked_shots >> D[i].Red_card >> D[i].Goals >> D[i].Pass_Accuracy;
        }
        cout << "DEFENCE : " << endl
             << endl;
        cout << "SNO F.Name    L.Name        Pos  AGE TEAM                  COUNTRY" << endl
             << endl;
        for (int i = 0; i < 107; i++)
        {
            cout << left << setw(4) << id[i] << setw(10) << D[i].First_name << setw(14) << D[i].Last_name << setw(5) << D[i].Position << setw(4) << D[i].Age << setw(22) << D[i].Team << setw(13) << D[i].Country << endl;
            cout << "-----------------------------------------------------------------------" << endl;
        }
        cout << endl;
    }
};
//GoalKeeper class (Inherited from Football class --> Will contain all the components of Football as well as its parent class Sports)
class GoalKeeper : public Football
{
protected:
public:
    int Clean_sheets;
    int Saves_made;
    int Goals_conceeded;

    GoalKeeper() //Default constructor for Goalkeeper class
    {
        Clean_sheets = 0;
        Saves_made = 0;
        Goals_conceeded = 0;
    }

    //Parameterized Constructor for Goalkeeper class
    GoalKeeper(string first_name, string last_name, int age, string team, string country, int win, int lost, string position, int no_of_matches, int assist, int pass_accuracy, int red_card, int draw, int clean_sheets, int saves_made, int goals_conceeded) : Football(first_name, last_name, age, team, country, win, lost, no_of_matches, position, pass_accuracy, red_card, draw)
    {
        Clean_sheets = clean_sheets;
        Saves_made = saves_made;
        Goals_conceeded = goals_conceeded;
    }

    ~GoalKeeper() {} //Destructor for Goalkeeper class

    void Search_player_f_gk(GoalKeeper *Gk, string name)
    {
        fstream psearch_gk("gk.txt");
        int id[30];
        int _id = 1;
        for (int i = 0; i < 30; i++)
        {
            id[i] = _id;
            _id++;
        }
        psearch_gk.seekg(0);
        for (int i = 0; i < 27; i++)
        {
            psearch_gk >> Gk[i].First_name >> Gk[i].Last_name >> Gk[i].Position >> Gk[i].Age >> Gk[i].Team >> Gk[i].Country >> Gk[i].No_of_matches >> Gk[i].Clean_sheets >> Gk[i].Saves_made >> Gk[i].Goals_conceeded >> Gk[i].Red_card;
        }

        int check = 0;

        for (int i = 0; i < 27; i++)
        {
            if (name == Gk[i].First_name || name == Gk[i].Last_name)
            {
                check = 1;
            }
        }

        if (check == 1)
        {
            cout << "SNO F.Name    L.Name        Pos  AGE TEAM                  COUNTRY      App  Cln.S Saves G.Con RCd" << endl
                 << endl
                 << endl;
        }
        else
        {
            cout << "This player does not exist" << endl
                 << endl;
        }

        for (int i = 0; i < 27; i++)
        {
            if (name == Gk[i].First_name || name == Gk[i].Last_name)
            {
                cout << left << setw(4) << id[i] << setw(10) << Gk[i].First_name << setw(14) << Gk[i].Last_name << setw(5) << Gk[i].Position << setw(4) << Gk[i].Age << setw(22) << Gk[i].Team << setw(13) << Gk[i].Country << setw(5) << Gk[i].No_of_matches << setw(6) << Gk[i].Clean_sheets << setw(6) << Gk[i].Saves_made << setw(6) << Gk[i].Goals_conceeded << setw(3) << Gk[i].Red_card << endl;
                cout << "-----------------------------------------------------------------------------------------------------" << endl;
            }
        }
    }

    void Player_display_f_gk(GoalKeeper *Gk)
    {
        fstream player_f_gk("gk.txt");

        int id[30];
        int _id = 1;
        for (int i = 0; i < 30; i++)
        {
            id[i] = _id;
            _id++;
        }
        player_f_gk.seekg(0);
        for (int i = 0; i < 27; i++)
        {
            player_f_gk >> Gk[i].First_name >> Gk[i].Last_name >> Gk[i].Position >> Gk[i].Age >> Gk[i].Team >> Gk[i].Country >> Gk[i].No_of_matches >> Gk[i].Clean_sheets >> Gk[i].Saves_made >> Gk[i].Goals_conceeded >> Gk[i].Red_card;
        }
        cout << "GOAL-KEEPERS : " << endl
             << endl;
        cout << "SNO F.Name    L.Name        Pos  AGE TEAM                  COUNTRY" << endl
             << endl;

        for (int i = 0; i < 27; i++)
        {
            cout << left << setw(4) << id[i] << setw(10) << Gk[i].First_name << setw(14) << Gk[i].Last_name << setw(5) << Gk[i].Position << setw(4) << Gk[i].Age << setw(22) << Gk[i].Team << setw(13) << Gk[i].Country << endl;
            cout << "-----------------------------------------------------------------------" << endl;
        }
        cout << endl;
    }

    void Display_stats_f_gk(GoalKeeper *Gk)
    {
        fstream stats_f_gk("gk.txt");
        int id[30];
        int _id = 1;
        for (int i = 0; i < 30; i++)
        {
            id[i] = _id;
            _id++;
        }

        stats_f_gk.seekg(0);
        for (int i = 0; i < 27; i++)
        {
            stats_f_gk >> Gk[i].First_name >> Gk[i].Last_name >> Gk[i].Position >> Gk[i].Age >> Gk[i].Team >> Gk[i].Country >> Gk[i].No_of_matches >> Gk[i].Clean_sheets >> Gk[i].Saves_made >> Gk[i].Goals_conceeded >> Gk[i].Red_card;
        }
        cout << "SNO F.Name    L.Name        Pos  AGE TEAM                  COUNTRY      App  Cln.S Saves  G.Con  RCd" << endl
             << endl
             << endl;
        for (int i = 0; i < 27; i++)
        {
            cout << left << setw(4) << id[i] << setw(10) << Gk[i].First_name << setw(14) << Gk[i].Last_name << setw(5) << Gk[i].Position << setw(4) << Gk[i].Age << setw(22) << Gk[i].Team << setw(13) << Gk[i].Country << setw(5) << Gk[i].No_of_matches << setw(6) << Gk[i].Clean_sheets << setw(7) << Gk[i].Saves_made << setw(7) << Gk[i].Goals_conceeded << setw(3) << Gk[i].Red_card << endl;
            cout << "-----------------------------------------------------------------------------------------------------" << endl;
        }
    }
};

//Base class for basketball ---> Inherited from class "Sports"
class Basketball : public Sports
{
protected:
    string Position;
    int Minutes_played;
    int Points;
    int Assists;
    int Rebounds;
    int Field_goal_made;
    int Field_goal_attempt;
    float Field_goal_percentage;
    int Three_ptr_made;
    int Three_ptr_attempt;
    float Three_ptr_percentage;
    int Free_throw_made;
    int Free_throw_attempt;
    float Free_throw_percentage;
    int Steals;
    int Blocks;
    int Turnover;

public:
    Basketball() //Default constructor for Basketball class
    {
        Position = "";
        Minutes_played = 0;
        Points = 0;
        Assists = 0;
        Rebounds = 0;
        Field_goal_made = 0;
        Field_goal_attempt = 0;
        Field_goal_percentage = 0;
        Three_ptr_made = 0;
        Three_ptr_attempt = 0;
        Three_ptr_percentage = 0;
        Free_throw_made = 0;
        Free_throw_attempt = 0;
        Free_throw_percentage = 0;
        Steals = 0;
        Blocks = 0;
        Turnover = 0;
    }

    //Parameterized Constructor for Basketball class
    Basketball(string first_name, string last_name, int age, string team, string country, int win, int lost, int no_of_matches, string position, int minutes_played, int points, int assists, int rebounds, int field_goal_made, int field_goal_attempt, float field_goal_percentage, int three_ptr_made, int three_ptr_attempt, float three_ptr_percentage, int free_throw_made, int free_throw_attempt, float free_throw_percentage, int steals, int blocks, int turnover) : Sports(first_name, last_name, age, team, country, win, lost, no_of_matches)
    {
        Position = position;
        Minutes_played = minutes_played;
        Points = points;
        Assists = assists;
        Rebounds = rebounds;
        Field_goal_made = field_goal_made;
        Field_goal_attempt = field_goal_attempt;
        Field_goal_percentage = field_goal_percentage;
        Three_ptr_made = three_ptr_made;
        Three_ptr_attempt = three_ptr_attempt;
        Three_ptr_percentage = three_ptr_percentage;
        Free_throw_made = free_throw_made;
        Free_throw_attempt = free_throw_attempt;
        Free_throw_percentage = free_throw_percentage;
        Steals = steals;
        Blocks = blocks;
        Turnover = turnover;
    }

    ~Basketball() {} //Destructor for Basketball class

    void Display_content_b() //Main Display of basketball
    {
        cout << "                                      **********************************" << endl;
        cout << "                                      WELCOME TO SPORTS ANALYZER PROGRAM" << endl;
        cout << "                                      **********************************" << endl
             << endl
             << endl;
        cout << "                                      >>>> Welcome to Basketball <<<<" << endl
             << endl;
        cout << "                                      1. View Teams " << endl;
        cout << "                                      2. View Players " << endl;
        cout << "                                      3. Stats " << endl;
        cout << "                                      4. Standings " << endl;
        cout << "                                      5. Return to Main Menu" << endl;
        cout << "                                      0. EXIT" << endl
             << endl;
        cout << "                                      Enter your Choice: ";
    }

    void Team_display_b()
    {
        fstream team_b("team_b.txt"); //Team txt file
        string b;

        if (!team_b) // if there's an error opening the team file
            cout << "Error opening the file!!" << endl;
        else
        {
            while (!team_b.eof()) //reads the file till eof
            {
                getline(team_b, b);
                cout << b << endl;
            }
        }
    }

    void Search_player_b(Basketball *B)
    {
        fstream search_b("basketball_demo.txt");
        if (!search_b) // if there's an error opening the team file
            cout << "Error opening the file!!" << endl;

        int id[400];                  // ID allotted to every player
        search_b.seekg(0);            //makes the pointer start reading from the beginning
        for (int i = 0; i < 300; i++) //inputs all the data into class's objects
        {
            search_b >> id[i] >> B[i].First_name >> B[i].Last_name >> B[i].Age >> B[i].Team >> B[i].Country >> B[i].Position >> B[i].No_of_matches >> B[i].Win >> B[i].Lost >> B[i].Minutes_played >> B[i].Points >> B[i].Assists >> B[i].Rebounds >> B[i].Field_goal_made >> B[i].Field_goal_attempt >> B[i].Field_goal_percentage >> B[i].Three_ptr_made >> B[i].Three_ptr_attempt >> B[i].Three_ptr_percentage >> B[i].Free_throw_made >> B[i].Free_throw_attempt >> B[i].Free_throw_percentage >> B[i].Steals >> B[i].Blocks >> B[i].Turnover;
        }

        cout << "Enter name of the player to search : ";
        string name; // player to be searched
        cin >> name;

        int check = 0;

        for (int i = 0; i < 300; i++)
        {
            if (name == B[i].First_name || name == B[i].Last_name)
            {
                check = 1;
            }
        }

        if (check == 1)
        {
            cout << "F.Name   L.Name           AGE  TEAM         COUNTRY        POS            TM MP   PTS  ASS REB FGM FGA  FG%  3PM 3PA 3P%  FTM FTA FT%  STL BLK TO " << endl
                 << endl;
        }
        else
        {
            cout << "This player does not exist" << endl
                 << endl;
        }

        for (int i = 0; i < 300; i++)
        {
            if (name == B[i].First_name || name == B[i].Last_name) // checks both first and last name of the player from the file list
            {
                cout << left << setw(9) << B[i].First_name << setw(17) << B[i].Last_name << setw(5) << B[i].Age << setw(13) << B[i].Team << setw(15) << B[i].Country << setw(15) << B[i].Position << setw(3) << B[i].No_of_matches << setw(5) << B[i].Minutes_played << setw(5) << B[i].Points << setw(4) << B[i].Assists << setw(4) << B[i].Rebounds << setw(4) << B[i].Field_goal_made << setw(5) << B[i].Field_goal_attempt << setw(5) << B[i].Field_goal_percentage << setw(4) << B[i].Three_ptr_made << setw(4) << B[i].Three_ptr_attempt << setw(5) << B[i].Three_ptr_percentage << setw(4) << B[i].Free_throw_made << setw(4) << B[i].Free_throw_attempt << setw(5) << B[i].Free_throw_percentage << setw(4) << B[i].Steals << setw(4) << B[i].Blocks << setw(4) << B[i].Turnover << endl;
                cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
        }
    }

    void Player_display_b(Basketball *B)
    {
        fstream player_b("basketball_demo.txt");
        if (!player_b)
            cout << "Error opening the file!!" << endl;
        int id[400];                  // ID allotted to every player
        player_b.seekg(0);            //makes the pointer start reading from the beginning
        for (int i = 0; i < 300; i++) //inputs all the data into class's objects
        {
            player_b >> id[i] >> B[i].First_name >> B[i].Last_name >> B[i].Age >> B[i].Team >> B[i].Country >> B[i].Position >> B[i].No_of_matches >> B[i].Win >> B[i].Lost >> B[i].Minutes_played >> B[i].Points >> B[i].Assists >> B[i].Rebounds >> B[i].Field_goal_made >> B[i].Field_goal_attempt >> B[i].Field_goal_percentage >> B[i].Three_ptr_made >> B[i].Three_ptr_attempt >> B[i].Three_ptr_percentage >> B[i].Free_throw_made >> B[i].Free_throw_attempt >> B[i].Free_throw_percentage >> B[i].Steals >> B[i].Blocks >> B[i].Turnover;
        }
        cout << "SNO F.NAME   L.NAME           AGE   TEAM         COUNTRY " << endl
             << endl
             << endl;
        for (int i = 0; i < 300; i++) //displays all the players in the league after reading from the file
        {
            cout << left << setw(4) << id[i] << left << setw(9) << B[i].First_name << left << setw(17) << B[i].Last_name << left << setw(6) << B[i].Age << left << setw(13) << B[i].Team << left << setw(15) << B[i].Country << endl;
            cout << "---------------------------------------------------------------" << endl;
        }
    }

    void Display_top10_b_p(Basketball *B)
    {
        fstream top10_b("basketball_demo.txt");
        if (!top10_b)
            cout << "Error opening the file!!" << endl;

        int id[400];                  // ID allotted to every player
        top10_b.seekg(0);             //makes the pointer start reading from the beginning
        for (int i = 0; i < 300; i++) //inputs all the data into class's objects
        {
            top10_b >> id[i] >> B[i].First_name >> B[i].Last_name >> B[i].Age >> B[i].Team >> B[i].Country >> B[i].Position >> B[i].No_of_matches >> B[i].Win >> B[i].Lost >> B[i].Minutes_played >> B[i].Points >> B[i].Assists >> B[i].Rebounds >> B[i].Field_goal_made >> B[i].Field_goal_attempt >> B[i].Field_goal_percentage >> B[i].Three_ptr_made >> B[i].Three_ptr_attempt >> B[i].Three_ptr_percentage >> B[i].Free_throw_made >> B[i].Free_throw_attempt >> B[i].Free_throw_percentage >> B[i].Steals >> B[i].Blocks >> B[i].Turnover;
        }

        int points[300];
        for (int i = 0; i < 300; i++)
        {
            points[i] = B[i].Points; //stores all Points from the file in a array
        }
        int n = sizeof(points) / sizeof(points[0]);
        sort(points, points + n, greater<int>()); // sort function to arrange them into descending order

        int n1 = 300;
        for (int i = 0; i < n1; ++i)
        {
            for (int j = i + 1; j < n1;)
            {
                if (points[i] == points[j]) //checks for multiple instances of same points
                {
                    for (int k = j; k < n1 - 1; ++k)
                        points[k] = points[k + 1];
                    --n1;
                }
                else
                    ++j;
            }
        }

        cout << "Rank F.Name   L.Name           Team         MP   Points" << endl
             << endl;

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 300; j++)
            {
                if (points[i] == B[j].Points) // checks where the given (point) occurs in the stat file
                {
                    cout << left << setw(5) << id[i] << setw(9) << B[j].First_name << setw(17) << B[j].Last_name << setw(13) << B[j].Team << setw(5) << B[j].No_of_matches << setw(5) << B[j].Points << endl;
                    cout << "--------------------------------------------------------" << endl;
                }
            }
        }
    }

    void Display_top10_b_a(Basketball *B)
    {
        fstream top10_b("basketball_demo.txt");
        int id[400];
        top10_b.seekg(0);
        for (int i = 0; i < 300; i++)
        {
            top10_b >> id[i] >> B[i].First_name >> B[i].Last_name >> B[i].Age >> B[i].Team >> B[i].Country >> B[i].Position >> B[i].No_of_matches >> B[i].Win >> B[i].Lost >> B[i].Minutes_played >> B[i].Points >> B[i].Assists >> B[i].Rebounds >> B[i].Field_goal_made >> B[i].Field_goal_attempt >> B[i].Field_goal_percentage >> B[i].Three_ptr_made >> B[i].Three_ptr_attempt >> B[i].Three_ptr_percentage >> B[i].Free_throw_made >> B[i].Free_throw_attempt >> B[i].Free_throw_percentage >> B[i].Steals >> B[i].Blocks >> B[i].Turnover;
        }

        int assist[300];
        for (int i = 0; i < 300; i++)
        {
            assist[i] = B[i].Assists;
        }
        int n = sizeof(assist) / sizeof(assist[0]);
        sort(assist, assist + n, greater<int>());

        int n1 = 300;
        for (int i = 0; i < n1; ++i)
        {
            for (int j = i + 1; j < n1;)
            {
                if (assist[i] == assist[j])
                {
                    for (int k = j; k < n1 - 1; ++k)
                        assist[k] = assist[k + 1];
                    --n1;
                }
                else
                    ++j;
            }
        }

        cout << "Rank F.Name   L.Name           Team         MP   Assists" << endl
             << endl;

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 300; j++)
            {
                if (assist[i] == B[j].Assists)
                {
                    cout << left << setw(5) << id[i] << setw(9) << B[j].First_name << setw(17) << B[j].Last_name << setw(13) << B[j].Team << setw(5) << B[j].No_of_matches << setw(5) << B[j].Assists << endl;
                    cout << "--------------------------------------------------------" << endl;
                }
            }
        }
    }

    void Display_top10_b_r(Basketball *B)
    {
        fstream top10_b("basketball_demo.txt");
        int id[400];
        top10_b.seekg(0);
        for (int i = 0; i < 300; i++)
        {
            top10_b >> id[i] >> B[i].First_name >> B[i].Last_name >> B[i].Age >> B[i].Team >> B[i].Country >> B[i].Position >> B[i].No_of_matches >> B[i].Win >> B[i].Lost >> B[i].Minutes_played >> B[i].Points >> B[i].Assists >> B[i].Rebounds >> B[i].Field_goal_made >> B[i].Field_goal_attempt >> B[i].Field_goal_percentage >> B[i].Three_ptr_made >> B[i].Three_ptr_attempt >> B[i].Three_ptr_percentage >> B[i].Free_throw_made >> B[i].Free_throw_attempt >> B[i].Free_throw_percentage >> B[i].Steals >> B[i].Blocks >> B[i].Turnover;
        }

        int rebound[300];
        for (int i = 0; i < 300; i++)
        {
            rebound[i] = B[i].Rebounds;
        }
        int n = sizeof(rebound) / sizeof(rebound[0]);
        sort(rebound, rebound + n, greater<int>());

        int n1 = 300;
        for (int i = 0; i < n1; ++i)
        {
            for (int j = i + 1; j < n1;)
            {
                if (rebound[i] == rebound[j])
                {
                    for (int k = j; k < n1 - 1; ++k)
                        rebound[k] = rebound[k + 1];
                    --n1;
                }
                else
                    ++j;
            }
        }

        cout << "Rank F.Name   L.Name           Team         MP   Rebounds" << endl
             << endl;

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 300; j++)
            {
                if (rebound[i] == B[j].Rebounds)
                {
                    cout << left << setw(5) << id[i] << setw(9) << B[j].First_name << setw(17) << B[j].Last_name << setw(13) << B[j].Team << setw(5) << B[j].No_of_matches << setw(5) << B[j].Rebounds << endl;
                    cout << "---------------------------------------------------------" << endl;
                }
            }
        }
    }

    void Display_top10_b_fg(Basketball *B)
    {
        fstream top10_b("basketball_demo.txt");
        int id[400];
        top10_b.seekg(0);
        for (int i = 0; i < 300; i++)
        {
            top10_b >> id[i] >> B[i].First_name >> B[i].Last_name >> B[i].Age >> B[i].Team >> B[i].Country >> B[i].Position >> B[i].No_of_matches >> B[i].Win >> B[i].Lost >> B[i].Minutes_played >> B[i].Points >> B[i].Assists >> B[i].Rebounds >> B[i].Field_goal_made >> B[i].Field_goal_attempt >> B[i].Field_goal_percentage >> B[i].Three_ptr_made >> B[i].Three_ptr_attempt >> B[i].Three_ptr_percentage >> B[i].Free_throw_made >> B[i].Free_throw_attempt >> B[i].Free_throw_percentage >> B[i].Steals >> B[i].Blocks >> B[i].Turnover;
        }

        float field_goal[300];
        for (int i = 0; i < 300; i++)
        {
            field_goal[i] = B[i].Field_goal_percentage;
        }
        int n = sizeof(field_goal) / sizeof(field_goal[0]);
        sort(field_goal, field_goal + n, greater<int>());

        int n1 = 300;
        for (int i = 0; i < n1; ++i)
        {
            for (int j = i + 1; j < n1;)
            {
                if (field_goal[i] == field_goal[j])
                {
                    for (int k = j; k < n1 - 1; ++k)
                        field_goal[k] = field_goal[k + 1];
                    --n1;
                }
                else
                    ++j;
            }
        }

        cout << "Rank F.Name   L.Name           Team         MP   FG%" << endl
             << endl;

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 300; j++)
            {
                if (field_goal[i] == B[j].Field_goal_percentage)
                {
                    cout << left << setw(5) << id[i] << setw(9) << B[j].First_name << setw(17) << B[j].Last_name << setw(13) << B[j].Team << setw(5) << B[j].No_of_matches << setw(5) << B[j].Field_goal_percentage << endl;
                    cout << "------------------------------------------------------" << endl;
                }
            }
        }
    }

    void Display_top10_b_3p(Basketball *B)
    {
        fstream top10_b("basketball_demo.txt");
        int id[400];
        top10_b.seekg(0);
        for (int i = 0; i < 300; i++)
        {
            top10_b >> id[i] >> B[i].First_name >> B[i].Last_name >> B[i].Age >> B[i].Team >> B[i].Country >> B[i].Position >> B[i].No_of_matches >> B[i].Win >> B[i].Lost >> B[i].Minutes_played >> B[i].Points >> B[i].Assists >> B[i].Rebounds >> B[i].Field_goal_made >> B[i].Field_goal_attempt >> B[i].Field_goal_percentage >> B[i].Three_ptr_made >> B[i].Three_ptr_attempt >> B[i].Three_ptr_percentage >> B[i].Free_throw_made >> B[i].Free_throw_attempt >> B[i].Free_throw_percentage >> B[i].Steals >> B[i].Blocks >> B[i].Turnover;
        }

        float three_point[300];
        for (int i = 0; i < 300; i++)
        {
            three_point[i] = B[i].Three_ptr_percentage;
        }
        int n = sizeof(three_point) / sizeof(three_point[0]);
        sort(three_point, three_point + n, greater<int>());

        int n1 = 300;
        for (int i = 0; i < n1; ++i)
        {
            for (int j = i + 1; j < n1;)
            {
                if (three_point[i] == three_point[j])
                {
                    for (int k = j; k < n1 - 1; ++k)
                        three_point[k] = three_point[k + 1];
                    --n1;
                }
                else
                    ++j;
            }
        }

        cout << "Rank F.Name   L.Name           Team         MP   3P%" << endl
             << endl;

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 300; j++)
            {
                if (three_point[i] == B[j].Three_ptr_percentage)
                {
                    cout << left << setw(5) << id[i] << setw(9) << B[j].First_name << setw(17) << B[j].Last_name << setw(13) << B[j].Team << setw(5) << B[j].No_of_matches << setw(5) << B[j].Three_ptr_percentage << endl;
                    cout << "------------------------------------------------------" << endl;
                }
            }
        }
    }

    void Display_top10_b_ft(Basketball *B)
    {
        fstream top10_b("basketball_demo.txt");
        int id[400];
        top10_b.seekg(0);
        for (int i = 0; i < 300; i++)
        {
            top10_b >> id[i] >> B[i].First_name >> B[i].Last_name >> B[i].Age >> B[i].Team >> B[i].Country >> B[i].Position >> B[i].No_of_matches >> B[i].Win >> B[i].Lost >> B[i].Minutes_played >> B[i].Points >> B[i].Assists >> B[i].Rebounds >> B[i].Field_goal_made >> B[i].Field_goal_attempt >> B[i].Field_goal_percentage >> B[i].Three_ptr_made >> B[i].Three_ptr_attempt >> B[i].Three_ptr_percentage >> B[i].Free_throw_made >> B[i].Free_throw_attempt >> B[i].Free_throw_percentage >> B[i].Steals >> B[i].Blocks >> B[i].Turnover;
        }

        float free_throw[300];
        for (int i = 0; i < 300; i++)
        {
            free_throw[i] = B[i].Free_throw_percentage;
        }
        int n = sizeof(free_throw) / sizeof(free_throw[0]);
        sort(free_throw, free_throw + n, greater<int>());

        int n1 = 300;
        for (int i = 0; i < n1; ++i)
        {
            for (int j = i + 1; j < n1;)
            {
                if (free_throw[i] == free_throw[j])
                {
                    for (int k = j; k < n1 - 1; ++k)
                        free_throw[k] = free_throw[k + 1];
                    --n1;
                }
                else
                    ++j;
            }
        }

        cout << "Rank F.Name   L.Name           Team         MP   FT%" << endl
             << endl;

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 300; j++)
            {
                if (free_throw[i] == B[j].Free_throw_percentage)
                {
                    cout << left << setw(5) << id[i] << setw(9) << B[j].First_name << setw(17) << B[j].Last_name << setw(13) << B[j].Team << setw(5) << B[j].No_of_matches << setw(5) << B[j].Free_throw_percentage << endl;
                    cout << "------------------------------------------------------" << endl;
                }
            }
        }
    }

    void Stats_display_b(Basketball *B)
    {
        fstream stats_b("basketball_demo.txt");
        if (!stats_b)
            cout << "Error opening the file!!" << endl;

        int id[400];                  // ID allotted to every player
        stats_b.seekg(0);             //makes the pointer start reading from the beginning
        for (int i = 0; i < 300; i++) //inputs all the data into class's objects
        {
            stats_b >> id[i] >> B[i].First_name >> B[i].Last_name >> B[i].Age >> B[i].Team >> B[i].Country >> B[i].Position >> B[i].No_of_matches >> B[i].Win >> B[i].Lost >> B[i].Minutes_played >> B[i].Points >> B[i].Assists >> B[i].Rebounds >> B[i].Field_goal_made >> B[i].Field_goal_attempt >> B[i].Field_goal_percentage >> B[i].Three_ptr_made >> B[i].Three_ptr_attempt >> B[i].Three_ptr_percentage >> B[i].Free_throw_made >> B[i].Free_throw_attempt >> B[i].Free_throw_percentage >> B[i].Steals >> B[i].Blocks >> B[i].Turnover;
        }
        cout << "SNO F.Name   L.Name           AGE  TEAM         COUNTRY        POS            TM MP   PTS  ASS REB FGM FGA  FG%  3PM 3PA 3P%  FTM FTA FT%  STL BLK TO " << endl
             << endl
             << endl;
        for (int i = 0; i < 300; i++)
        {
            cout << left << setw(4) << id[i] << setw(9) << B[i].First_name << setw(17) << B[i].Last_name << setw(5) << B[i].Age << setw(13) << B[i].Team << setw(15) << B[i].Country << setw(15) << B[i].Position << setw(3) << B[i].No_of_matches << setw(5) << B[i].Minutes_played << setw(5) << B[i].Points << setw(4) << B[i].Assists << setw(4) << B[i].Rebounds << setw(4) << B[i].Field_goal_made << setw(5) << B[i].Field_goal_attempt << setw(5) << B[i].Field_goal_percentage << setw(4) << B[i].Three_ptr_made << setw(4) << B[i].Three_ptr_attempt << setw(5) << B[i].Three_ptr_percentage << setw(4) << B[i].Free_throw_made << setw(4) << B[i].Free_throw_attempt << setw(5) << B[i].Free_throw_percentage << setw(4) << B[i].Steals << setw(4) << B[i].Blocks << setw(4) << B[i].Turnover << endl;
            cout << "------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "Legends: F.Name = First Name, L.Name = Last Name, POS = Position, TM = Total Matches Played, MP = Minutes Played, PTS = Total Points, ASS = Total Assists, RPG = Total Rebounds, FGM = Field Goals Made, FGA = Field Goals Attempt, FG% = Field Goal Percentage, 3PM = 3-Pointers Made, 3PA = 3-Pointers Attempt, 3P% = 3-Point Percentage, FTM = Free Throws Made, FTA = Free Throw Attempts, FT% = Free Throw Percentage, STL = Steals, BLK = Bloacks, TO = Turnovers " << endl;
    }

    void Standings_display_b()
    {
        string b;
        fstream standings_b("standings_b.txt");
        if (!standings_b)
            cout << "Error opening the file!!" << endl;
        else
        {
            while (!standings_b.eof()) // copies whole file
            {
                getline(standings_b, b);
                cout << b << endl;
            }
        }
    }
};

//Base class for cricket ---> Inherited from class "Sports"
class Cricket : public Sports
{
protected:
public:
    int Innings;
    int Runs;
    float Batting_strike_rate;
    float Batting_average;
    int Fours;
    int Sixes;
    string Best_Batting_figure;

    Cricket() //Default Constructor for Cricket class
    {
        Innings = 0;
        Runs = 0;
        Batting_strike_rate = 0;
        Batting_average = 0;
        Fours = 0;
        Sixes = 0;
        Best_Batting_figure = "";
    }

    //Parameterized Constructor for Cricket class
    Cricket(string first_name, string last_name, int age, string team, string country, int win, int lost, int no_of_matches, int innings, int runs, float batting_strike_rate, float batting_average, int fours, int sixes, string best_batting_figure) : Sports(first_name, last_name, age, team, country, win, lost, no_of_matches)
    {
        Innings = innings;
        Runs = runs;
        Batting_strike_rate = batting_strike_rate;
        Batting_average = batting_average;
        Fours = fours;
        Sixes = sixes;
        Best_Batting_figure = best_batting_figure;
    }

    ~Cricket() {} //Destructor for Cricket class

    void Display_content_c() //Main content display of cricket
    {
        cout << "                                      **********************************" << endl;
        cout << "                                      WELCOME TO SPORTS ANALYZER PROGRAM" << endl;
        cout << "                                      **********************************" << endl
             << endl
             << endl;
        cout << "                                      >>>>>>> Welcome to Cricket <<<<<<" << endl
             << endl;
        cout << "                                      1. View Teams " << endl;
        cout << "                                      2. View Players " << endl;
        cout << "                                      3. Stats " << endl;
        cout << "                                      4. Standings " << endl;
        cout << "                                      5. Return to Main Menu" << endl;
        cout << "                                      0. EXIT" << endl
             << endl;
        cout << "                                      Enter your Choice: ";
    }

    void Team_display_c() //For diplaying the teams of cricket
    {
        fstream team_c("team_c.txt");
        string c;
        if (!team_c)
            cout << "Error" << endl;
        else
        {
            while (!team_c.eof())
            {
                getline(team_c, c);
                cout << c << endl;
            }
        }
    }

    void Standings_display_c()
    {
        fstream standings_c("standings_c.txt");
        string c;
        if (!standings_c)
            cout << "Error" << endl;
        else
        {
            while (!standings_c.eof())
            {
                getline(standings_c, c);
                cout << c << endl;
            }
        }
    }
};
//Batsman class (Inherited from Cricket class --> Will contain all the components of Cricket as well as its parent class Sports)
class Batsman : public Cricket
{
protected:
public:
    int Centuries;
    int Fifties;

    Batsman() //Default constructor for Batsman class
    {
        Centuries = 0;
        Fifties = 0;
    }

    //Parameterized constructor for Batsman class
    Batsman(string first_name, string last_name, int age, string team, string country, int win, int lost, int no_of_matches, int innings, int runs, float batting_strike_rate, float batting_average, int fours, int sixes, string best_batting_figure, int centuries, int fifties) : Cricket(first_name, last_name, age, team, country, win, lost, no_of_matches, innings, runs, batting_strike_rate, batting_average, fours, sixes, best_batting_figure)
    {
        Centuries = centuries;
        Fifties = fifties;
    }

    ~Batsman() {} //Destructor for Batsman class

    void Player_display_c_bt(Batsman *Bt) //For displaying the Batsman
    {
        fstream player_c_bt("batsman.txt");
        int id[100];
        player_c_bt.seekg(0);
        for (int i = 0; i < 45; i++)
        {
            player_c_bt >> id[i] >> Bt[i].First_name >> Bt[i].Last_name >> Bt[i].Age >> Bt[i].Team >> Bt[i].Country >> Bt[i].No_of_matches >> Bt[i].Innings >> Bt[i].Runs >> Bt[i].Batting_strike_rate >> Bt[i].Batting_average >> Bt[i].Fifties >> Bt[i].Centuries >> Bt[i].Best_Batting_figure >> Bt[i].Fours >> Bt[i].Sixes;
        }
        cout << "BATSMAN : " << endl
             << endl;
        cout << "F.Name     L.Name      AGE TEAM                        COUNTRY" << endl
             << endl
             << endl;
        for (int i = 0; i < 45; i++)
        {
            cout << left << setw(11) << Bt[i].First_name << setw(12) << Bt[i].Last_name << setw(4) << Bt[i].Age << setw(28) << Bt[i].Team << setw(13) << Bt[i].Country << endl;
            cout << "-------------------------------------------------------------------" << endl;
        }
        cout << endl;
    }

    void Search_player_c_bt(Batsman *Bt, string name)
    {
        fstream psearch_bt("batsman.txt");
        int id[50];
        psearch_bt.seekg(0);
        for (int i = 0; i < 45; i++)
        {
            psearch_bt >> id[i] >> Bt[i].First_name >> Bt[i].Last_name >> Bt[i].Age >> Bt[i].Team >> Bt[i].Country >> Bt[i].No_of_matches >> Bt[i].Innings >> Bt[i].Runs >> Bt[i].Batting_strike_rate >> Bt[i].Batting_average >> Bt[i].Fifties >> Bt[i].Centuries >> Bt[i].Best_Batting_figure >> Bt[i].Fours >> Bt[i].Sixes;
        }

        int check = 0;

        for (int i = 0; i < 45; i++)
        {
            if (name == Bt[i].First_name || name == Bt[i].Last_name)
            {
                check = 1;
            }
        }

        if (check == 1)
        {
            cout << "F.Name     L.Name      AGE TEAM                        COUNTRY      TM INN RUNS S.R.   Avg   50s  100s Best 4s 6s" << endl
                 << endl
                 << endl;
        }
        else
        {
            cout << "This player does not exist" << endl
                 << endl;
        }

        for (int i = 0; i < 45; i++)
        {
            if (name == Bt[i].First_name || name == Bt[i].Last_name)
            {
                cout << left << setw(11) << Bt[i].First_name << setw(12) << Bt[i].Last_name << setw(4) << Bt[i].Age << setw(28) << Bt[i].Team << setw(13) << Bt[i].Country << setw(3) << Bt[i].No_of_matches << setw(4) << Bt[i].Innings << setw(5) << Bt[i].Runs << setw(7) << Bt[i].Batting_strike_rate << setw(6) << Bt[i].Batting_average << setw(5) << Bt[i].Fifties << setw(5) << Bt[i].Centuries << setw(5) << Bt[i].Best_Batting_figure << setw(3) << Bt[i].Fours << setw(3) << Bt[i].Sixes << endl;
                cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
            }
        }
    }

    void Display_stats_c_bt(Batsman *Bt)
    {
        fstream stats_c_bt("batsman.txt");
        int id[50];

        stats_c_bt.seekg(0);
        for (int i = 0; i < 45; i++)
        {
            stats_c_bt >> id[i] >> Bt[i].First_name >> Bt[i].Last_name >> Bt[i].Age >> Bt[i].Team >> Bt[i].Country >> Bt[i].No_of_matches >> Bt[i].Innings >> Bt[i].Runs >> Bt[i].Batting_strike_rate >> Bt[i].Batting_average >> Bt[i].Fifties >> Bt[i].Centuries >> Bt[i].Best_Batting_figure >> Bt[i].Fours >> Bt[i].Sixes;
        }
        cout << "SNO F.Name     L.Name      AGE TEAM                        COUNTRY      TM INN RUNS S.R.   Avg   50s  100s Best 4s 6s" << endl
             << endl
             << endl;
        for (int i = 0; i < 45; i++)
        {
            cout << left << setw(4) << id[i] << setw(11) << Bt[i].First_name << setw(12) << Bt[i].Last_name << setw(4) << Bt[i].Age << setw(28) << Bt[i].Team << setw(13) << Bt[i].Country << setw(3) << Bt[i].No_of_matches << setw(4) << Bt[i].Innings << setw(5) << Bt[i].Runs << setw(7) << Bt[i].Batting_strike_rate << setw(6) << Bt[i].Batting_average << setw(5) << Bt[i].Fifties << setw(5) << Bt[i].Centuries << setw(5) << Bt[i].Best_Batting_figure << setw(4) << Bt[i].Fours << setw(3) << Bt[i].Sixes << endl;
            cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        }
    }
};
//Bowler class (Inherited from Cricket class --> Will contain all the components of Cricket as well as its parent class Sports)
class Bowler : public Cricket
{
protected:
public:
    int Wickets;
    float Bowling_average;
    int Four_wkt_hauls;
    float Economy;
    string Best_Bowling_figure;

    Bowler() //Default Constructor for Bowler class
    {
        Wickets = 0;
        Bowling_average = 0;
        Four_wkt_hauls = 0;
        Economy = 0;
        Best_Bowling_figure = "";
    }

    // Parameterized Constructor for Bowler class
    Bowler(string first_name, string last_name, int age, string team, string country, int win, int lost, int no_of_matches, int innings, int runs, float batting_strike_rate, float batting_average, int fours, int sixes, string best_batting_figure, int wickets, float bowling_average, int four_wkt_haul, float economy, string best_bowling_figure) : Cricket(first_name, last_name, age, team, country, win, lost, no_of_matches, innings, runs, batting_strike_rate, batting_average, fours, sixes, best_batting_figure)
    {
        Wickets = wickets;
        Bowling_average = bowling_average;
        Four_wkt_hauls = four_wkt_haul;
        Economy = economy;
        Best_Bowling_figure = best_bowling_figure;
    }

    ~Bowler() {} //Destructor for Bowler class

    void Player_display_c_bo(Bowler *Bo) //For displaying the Bowlers
    {
        fstream player_c_bo("bowlers.txt");
        int id[100];
        player_c_bo.seekg(0);
        for (int i = 0; i < 53; i++)
        {
            player_c_bo >> id[i] >> Bo[i].First_name >> Bo[i].Last_name >> Bo[i].Age >> Bo[i].Team >> Bo[i].Country >> Bo[i].No_of_matches >> Bo[i].Innings >> Bo[i].Wickets >> Bo[i].Economy >> Bo[i].Bowling_average >> Bo[i].Best_Bowling_figure >> Bo[i].Four_wkt_hauls >> Bo[i].Runs >> Bo[i].Batting_strike_rate >> Bo[i].Batting_average >> Bo[i].Best_Batting_figure >> Bo[i].Fours >> Bo[i].Sixes;
        }
        cout << "BOWLERS : " << endl
             << endl;
        cout << "F.Name       L.Name        AGE TEAM                        COUNTRY" << endl
             << endl
             << endl;
        for (int i = 0; i < 53; i++)
        {
            cout << left << setw(13) << Bo[i].First_name << setw(14) << Bo[i].Last_name << setw(4) << Bo[i].Age << setw(28) << Bo[i].Team << setw(13) << Bo[i].Country << endl;
            cout << "-----------------------------------------------------------------------" << endl;
        }
        cout << endl;
    }

    void Search_player_c_bo(Bowler *Bo, string name)
    {
        fstream psearch_bo("bowlers.txt");
        int id[60];
        psearch_bo.seekg(0);
        for (int i = 0; i < 53; i++)
        {
            psearch_bo >> id[i] >> Bo[i].First_name >> Bo[i].Last_name >> Bo[i].Age >> Bo[i].Team >> Bo[i].Country >> Bo[i].No_of_matches >> Bo[i].Innings >> Bo[i].Wickets >> Bo[i].Economy >> Bo[i].Bowling_average >> Bo[i].Best_Bowling_figure >> Bo[i].Four_wkt_hauls >> Bo[i].Runs >> Bo[i].Batting_strike_rate >> Bo[i].Batting_average >> Bo[i].Best_Batting_figure >> Bo[i].Fours >> Bo[i].Sixes;
        }

        int check = 0;

        for (int i = 0; i < 53; i++)
        {
            if (name == Bo[i].First_name || name == Bo[i].Last_name)
            {
                check = 1;
            }
        }

        if (check == 1)
        {
            cout << "F.Name       L.Name        AGE TEAM                        COUNTRY      TM INN W   ECO   Avg   Best 4WH RUNS S.R.   Avg   Best 4s  6s" << endl
                 << endl
                 << endl;
        }
        else
        {
            cout << "This player does not exist" << endl
                 << endl;
        }

        for (int i = 0; i < 53; i++)
        {
            if (name == Bo[i].First_name || name == Bo[i].Last_name)
            {
                cout << left << setw(13) << Bo[i].First_name << setw(14) << Bo[i].Last_name << setw(4) << Bo[i].Age << setw(28) << Bo[i].Team << setw(13) << Bo[i].Country << setw(3) << Bo[i].No_of_matches << setw(4) << Bo[i].Innings << setw(4) << Bo[i].Wickets << setw(6) << Bo[i].Economy << setw(6) << Bo[i].Bowling_average << setw(5) << Bo[i].Best_Bowling_figure << setw(4) << Bo[i].Four_wkt_hauls << setw(5) << Bo[i].Runs << setw(7) << Bo[i].Batting_strike_rate << setw(6) << Bo[i].Batting_average << setw(5) << Bo[i].Best_Batting_figure << setw(4) << Bo[i].Fours << setw(3) << Bo[i].Sixes << endl;
                cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
        }
    }

    void Display_stats_c_bo(Bowler *Bo)
    {
        fstream stats_c_bo("bowlers.txt");
        int id[60];

        stats_c_bo.seekg(0);
        for (int i = 0; i < 53; i++)
        {
            stats_c_bo >> id[i] >> Bo[i].First_name >> Bo[i].Last_name >> Bo[i].Age >> Bo[i].Team >> Bo[i].Country >> Bo[i].No_of_matches >> Bo[i].Innings >> Bo[i].Wickets >> Bo[i].Economy >> Bo[i].Bowling_average >> Bo[i].Best_Bowling_figure >> Bo[i].Four_wkt_hauls >> Bo[i].Runs >> Bo[i].Batting_strike_rate >> Bo[i].Batting_average >> Bo[i].Best_Batting_figure >> Bo[i].Fours >> Bo[i].Sixes;
        }
        cout << "SNO F.Name       L.Name        AGE TEAM                        COUNTRY      TM INN W   ECO   Avg   Best 4WH RUNS S.R.   Avg   Best 4s  6s" << endl
             << endl
             << endl;
        for (int i = 0; i < 53; i++)
        {
            cout << left << setw(4) << id[i] << setw(13) << Bo[i].First_name << setw(14) << Bo[i].Last_name << setw(4) << Bo[i].Age << setw(28) << Bo[i].Team << setw(13) << Bo[i].Country << setw(3) << Bo[i].No_of_matches << setw(4) << Bo[i].Innings << setw(4) << Bo[i].Wickets << setw(6) << Bo[i].Economy << setw(6) << Bo[i].Bowling_average << setw(5) << Bo[i].Best_Bowling_figure << setw(4) << Bo[i].Four_wkt_hauls << setw(5) << Bo[i].Runs << setw(7) << Bo[i].Batting_strike_rate << setw(6) << Bo[i].Batting_average << setw(5) << Bo[i].Best_Batting_figure << setw(4) << Bo[i].Fours << setw(3) << Bo[i].Sixes << endl;
            cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
        }
    }
};
//All-Rounder class (Inherited from Cricket class --> Will contain all the components of Cricket as well as its parent class Sports)
class All_rounder : public Cricket
{
protected:
public:
    int Centuries;
    int Fifties;
    int Wickets;
    float Bowling_average;
    int Four_wkt_hauls;
    float Economy;
    string Best_Bowling_figure;

    All_rounder() //Default constructor for All_rounder class
    {
        Centuries = 0;
        Fifties = 0;
        Wickets = 0;
        Bowling_average = 0;
        Four_wkt_hauls = 0;
        Economy = 0;
        Best_Bowling_figure = "";
    }

    //Parameterized constructor for All_rounder class
    All_rounder(string first_name, string last_name, int age, string team, string country, int win, int lost, int no_of_matches, int innings, int runs, float batting_strike_rate, float batting_average, int fours, int sixes, string best_batting_figure, int centuries, int fifties, int wickets, float bowling_average, int four_wkt_hauls, float economy, string best_bowling_figure) : Cricket(first_name, last_name, age, team, country, win, lost, no_of_matches, innings, runs, batting_strike_rate, batting_average, fours, sixes, best_batting_figure)
    {
        Centuries = centuries;
        Fifties = fifties;
        Wickets = wickets;
        Bowling_average = bowling_average;
        Four_wkt_hauls = four_wkt_hauls;
        Economy = economy;
        Best_Bowling_figure = best_bowling_figure;
    }

    ~All_rounder() {} //Destructor for All_rounder class

    void Player_display_c_ar(All_rounder *Ar) //For displaying the All-rounders
    {
        fstream player_c_ar("all_rounders.txt");
        int id[100];
        player_c_ar.seekg(0);
        for (int i = 0; i < 30; i++)
        {
            player_c_ar >> id[i] >> Ar[i].First_name >> Ar[i].Last_name >> Ar[i].Age >> Ar[i].Team >> Ar[i].Country >> Ar[i].No_of_matches >> Ar[i].Innings >> Ar[i].Runs >> Ar[i].Batting_strike_rate >> Ar[i].Batting_average >> Ar[i].Fifties >> Ar[i].Centuries >> Ar[i].Best_Batting_figure >> Ar[i].Fours >> Ar[i].Sixes >> Ar[i].Wickets >> Ar[i].Economy >> Ar[i].Bowling_average >> Ar[i].Best_Bowling_figure >> Ar[i].Four_wkt_hauls;
        }
        cout << "ALL-ROUNDERS : " << endl
             << endl;
        cout << "F.Name       L.Name        AGE TEAM                        COUNTRY" << endl
             << endl
             << endl;
        for (int i = 0; i < 30; i++)
        {
            cout << left << setw(13) << Ar[i].First_name << setw(14) << Ar[i].Last_name << setw(4) << Ar[i].Age << setw(28) << Ar[i].Team << setw(13) << Ar[i].Country << endl;
            cout << "-----------------------------------------------------------------------" << endl;
        }
        cout << endl;
    }

    void Search_player_c_ar(All_rounder *Ar, string name)
    {
        fstream psearch_ar("all_rounders.txt");
        int id[50];
        psearch_ar.seekg(0);
        for (int i = 0; i < 30; i++)
        {
            psearch_ar >> id[i] >> Ar[i].First_name >> Ar[i].Last_name >> Ar[i].Age >> Ar[i].Team >> Ar[i].Country >> Ar[i].No_of_matches >> Ar[i].Innings >> Ar[i].Runs >> Ar[i].Batting_strike_rate >> Ar[i].Batting_average >> Ar[i].Fifties >> Ar[i].Centuries >> Ar[i].Best_Batting_figure >> Ar[i].Fours >> Ar[i].Sixes >> Ar[i].Wickets >> Ar[i].Economy >> Ar[i].Bowling_average >> Ar[i].Best_Bowling_figure >> Ar[i].Four_wkt_hauls;
        }

        int check = 0;

        for (int i = 0; i < 30; i++)
        {
            if (name == Ar[i].First_name || name == Ar[i].Last_name)
            {
                check = 1;
            }
        }

        if (check == 1)
        {
            cout << "F.Name       L.Name        AGE TEAM                        COUNTRY      TM INN RUNS S.R.   Avg   50s 100s Best 4s  6s W   ECO   Avg   Best 4WH" << endl
                 << endl
                 << endl;
        }
        else
        {
            cout << "This player does not exist" << endl
                 << endl;
        }

        for (int i = 0; i < 30; i++)
        {
            if (name == Ar[i].First_name || name == Ar[i].Last_name)
            {
                cout << left << setw(13) << Ar[i].First_name << setw(14) << Ar[i].Last_name << setw(4) << Ar[i].Age << setw(28) << Ar[i].Team << setw(13) << Ar[i].Country << setw(3) << Ar[i].No_of_matches << setw(4) << Ar[i].Innings << setw(5) << Ar[i].Runs << setw(7) << Ar[i].Batting_strike_rate << setw(6) << Ar[i].Batting_average << setw(4) << Ar[i].Fifties << setw(5) << Ar[i].Centuries << setw(5) << Ar[i].Best_Batting_figure << setw(4) << Ar[i].Fours << setw(3) << Ar[i].Sixes << setw(4) << Ar[i].Wickets << setw(6) << Ar[i].Economy << setw(6) << Ar[i].Bowling_average << setw(5) << Ar[i].Best_Bowling_figure << setw(4) << Ar[i].Four_wkt_hauls << endl;
                cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
        }
    }

    void Display_stats_c_ar(All_rounder *Ar)
    {
        fstream stats_c_ar("all_rounders.txt");
        int id[30];

        stats_c_ar.seekg(0);
        for (int i = 0; i < 30; i++)
        {
            stats_c_ar >> id[i] >> Ar[i].First_name >> Ar[i].Last_name >> Ar[i].Age >> Ar[i].Team >> Ar[i].Country >> Ar[i].No_of_matches >> Ar[i].Innings >> Ar[i].Runs >> Ar[i].Batting_strike_rate >> Ar[i].Batting_average >> Ar[i].Fifties >> Ar[i].Centuries >> Ar[i].Best_Batting_figure >> Ar[i].Fours >> Ar[i].Sixes >> Ar[i].Wickets >> Ar[i].Economy >> Ar[i].Bowling_average >> Ar[i].Best_Bowling_figure >> Ar[i].Four_wkt_hauls;
        }
        cout << "SNO F.Name       L.Name        AGE TEAM                        COUNTRY      TM INN RUNS S.R.   Avg   50s 100s Best 4s  6s W   ECO   Avg   Best 4WH" << endl
             << endl
             << endl;
        for (int i = 0; i < 30; i++)
        {
            cout << left << setw(4) << id[i] << setw(13) << Ar[i].First_name << setw(14) << Ar[i].Last_name << setw(4) << Ar[i].Age << setw(28) << Ar[i].Team << setw(13) << Ar[i].Country << setw(3) << Ar[i].No_of_matches << setw(4) << Ar[i].Innings << setw(5) << Ar[i].Runs << setw(7) << Ar[i].Batting_strike_rate << setw(6) << Ar[i].Batting_average << setw(4) << Ar[i].Fifties << setw(5) << Ar[i].Centuries << setw(5) << Ar[i].Best_Batting_figure << setw(4) << Ar[i].Fours << setw(3) << Ar[i].Sixes << setw(4) << Ar[i].Wickets << setw(6) << Ar[i].Economy << setw(6) << Ar[i].Bowling_average << setw(5) << Ar[i].Best_Bowling_figure << setw(4) << Ar[i].Four_wkt_hauls << endl;
            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        }
    }
};
//Wicket-Keeper class (Inherited from Cricket class --> Will contain all the components of Cricket as well as its parent class Sports)
class Wicket_keeper : public Cricket
{
protected:
public:
    int Centuries;
    int Fifties;
    int Stumps;
    int Catches;

    Wicket_keeper() //Default Constructor for Wicket_keeper class;
    {
        Centuries = 0;
        Fifties = 0;
        Stumps = 0;
        Catches = 0;
    }

    //Parameterized constructor for Wicket_keeper class
    Wicket_keeper(string first_name, string last_name, int age, string team, string country, int win, int lost, int no_of_matches, int innings, int runs, float batting_strike_rate, float batting_average, int fours, int sixes, string best_batting_figure, int centuries, int fifties, int stumps, int catches) : Cricket(first_name, last_name, age, team, country, win, lost, no_of_matches, innings, runs, batting_strike_rate, batting_average, fours, sixes, best_batting_figure)
    {
        Centuries = centuries;
        Fifties = fifties;
        Stumps = stumps;
        Catches = catches;
    }

    void Player_display_c_wk(Wicket_keeper *Wk) //For displaying the wicket-keepers
    {
        fstream player_c_wk("WICKETKEEPERS.txt");
        player_c_wk.seekg(0);

        int id[100];

        for (int i = 0; i < 8; i++) //Reading WICKETKEEPERS.txt file in the object
        {
            player_c_wk >> id[i] >> Wk[i].First_name >> Wk[i].Last_name >> Wk[i].Age >> Wk[i].Team >> Wk[i].Country >> Wk[i].No_of_matches >> Wk[i].Innings >> Wk[i].Stumps >> Wk[i].Catches >> Wk[i].Runs >> Wk[i].Batting_strike_rate >> Wk[i].Batting_average >> Wk[i].Fifties >> Wk[i].Centuries >> Wk[i].Best_Batting_figure >> Wk[i].Fours >> Wk[i].Sixes;
        }

        cout << "WICKET-KEEPERS : " << endl
             << endl;
        cout << "F.Name       L.Name        AGE TEAM                        COUNTRY" << endl
             << endl
             << endl;

        for (int i = 0; i < 8; i++) //Displaying all wicketkeepers from the file
        {
            cout << left << setw(13) << Wk[i].First_name << setw(14) << Wk[i].Last_name << setw(4) << Wk[i].Age << setw(28) << Wk[i].Team << setw(13) << Wk[i].Country << endl;
            cout << "-----------------------------------------------------------------------" << endl;
        }
        cout << endl;
    }

    void Search_player_c_wk(Wicket_keeper *Wk, string name) //For searching a specific player from the file via First Name search
    {
        fstream psearch_wk("WICKETKEEPERS.txt");
        int id[10];

        psearch_wk.seekg(0);

        for (int i = 0; i < 8; i++) //Reading WICKETKEEPERS.txt file in the object
        {
            psearch_wk >> id[i] >> Wk[i].First_name >> Wk[i].Last_name >> Wk[i].Age >> Wk[i].Team >> Wk[i].Country >> Wk[i].No_of_matches >> Wk[i].Innings >> Wk[i].Stumps >> Wk[i].Catches >> Wk[i].Runs >> Wk[i].Batting_strike_rate >> Wk[i].Batting_average >> Wk[i].Fifties >> Wk[i].Centuries >> Wk[i].Best_Batting_figure >> Wk[i].Fours >> Wk[i].Sixes;
        }

        int check = 0;

        for (int i = 0; i < 8; i++)
        {
            if (name == Wk[i].First_name || name == Wk[i].Last_name)
            {
                check = 1;
            }
        }

        if (check == 1)
        {
            cout << "F.Name       L.Name        AGE TEAM                        COUNTRY      TM INN C   St  RUNS S.R.   Avg   50s 100s Best 4s  6s" << endl
                 << endl
                 << endl;
        }
        else
        {
            cout << "This player does not exist" << endl
                 << endl;
        }

        for (int i = 0; i < 8; i++)
        {
            if (name == Wk[i].First_name || name == Wk[i].Last_name) //Checking and printing the required Wicket-keeper's Data
            {
                cout << left << setw(13) << Wk[i].First_name << setw(14) << Wk[i].Last_name << setw(4) << Wk[i].Age << setw(28) << Wk[i].Team << setw(13) << Wk[i].Country << setw(3) << Wk[i].No_of_matches << setw(4) << Wk[i].Innings << setw(4) << Wk[i].Stumps << setw(4) << Wk[i].Catches << setw(5) << Wk[i].Runs << setw(7) << Wk[i].Batting_strike_rate << setw(6) << Wk[i].Batting_average << setw(4) << Wk[i].Fifties << setw(5) << Wk[i].Centuries << setw(5) << Wk[i].Best_Batting_figure << setw(4) << Wk[i].Fours << setw(3) << Wk[i].Sixes << endl;
                cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
        }
    }

    void Display_stats_c_wk(Wicket_keeper *Wk)
    {
        fstream stats_c_wk("WICKETKEEPERS.txt");
        int id[10];

        stats_c_wk.seekg(0);
        for (int i = 0; i < 8; i++)
        {
            stats_c_wk >> id[i] >> Wk[i].First_name >> Wk[i].Last_name >> Wk[i].Age >> Wk[i].Team >> Wk[i].Country >> Wk[i].No_of_matches >> Wk[i].Innings >> Wk[i].Stumps >> Wk[i].Catches >> Wk[i].Runs >> Wk[i].Batting_strike_rate >> Wk[i].Batting_average >> Wk[i].Fifties >> Wk[i].Centuries >> Wk[i].Best_Batting_figure >> Wk[i].Fours >> Wk[i].Sixes;
        }
        cout << "SNO F.Name       L.Name        AGE TEAM                        COUNTRY      TM INN C   St  RUNS S.R.   Avg   50s 100s Best 4s  6s" << endl
             << endl
             << endl;
        for (int i = 0; i < 8; i++)
        {
            cout << left << setw(4) << id[i] << setw(13) << Wk[i].First_name << setw(14) << Wk[i].Last_name << setw(4) << Wk[i].Age << setw(28) << Wk[i].Team << setw(13) << Wk[i].Country << setw(3) << Wk[i].No_of_matches << setw(4) << Wk[i].Innings << setw(4) << Wk[i].Stumps << setw(4) << Wk[i].Catches << setw(5) << Wk[i].Runs << setw(7) << Wk[i].Batting_strike_rate << setw(6) << Wk[i].Batting_average << setw(4) << Wk[i].Fifties << setw(5) << Wk[i].Centuries << setw(5) << Wk[i].Best_Batting_figure << setw(4) << Wk[i].Fours << setw(3) << Wk[i].Sixes << endl;
            cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
        }
    }
};

void Display_top10_run(Batsman *Bt, Bowler *Bo, All_rounder *Ar, Wicket_keeper *Wk)
{
    fstream bat("batsman.txt");
    if (!bat)
        cout << "Error opening the file!!" << endl;
    fstream bowl("bowlers.txt");
    if (!bowl)
        cout << "Error opening the file!!" << endl;
    fstream allrounder("all_rounders.txt");
    if (!allrounder)
        cout << "Error opening the file!!" << endl;
    fstream wktkeeper("WICKETKEEPERS.txt");
    if (!wktkeeper)
        cout << "Error opening the file!!" << endl;

    int id[136];
    bat.seekg(0);
    bowl.seekg(0);
    allrounder.seekg(0);
    wktkeeper.seekg(0);

    for (int i = 0; i < 45; i++)
    {
        bat >> id[i] >> Bt[i].First_name >> Bt[i].Last_name >> Bt[i].Age >> Bt[i].Team >> Bt[i].Country >> Bt[i].No_of_matches >> Bt[i].Innings >> Bt[i].Runs >> Bt[i].Batting_strike_rate >> Bt[i].Batting_average >> Bt[i].Fifties >> Bt[i].Centuries >> Bt[i].Best_Batting_figure >> Bt[i].Fours >> Bt[i].Sixes;
    }
    for (int i = 45; i < 98; i++)
    {
        bowl >> id[i] >> Bo[i - 45].First_name >> Bo[i - 45].Last_name >> Bo[i - 45].Age >> Bo[i - 45].Team >> Bo[i - 45].Country >> Bo[i - 45].No_of_matches >> Bo[i - 45].Innings >> Bo[i - 45].Wickets >> Bo[i - 45].Economy >> Bo[i - 45].Bowling_average >> Bo[i - 45].Best_Bowling_figure >> Bo[i - 45].Four_wkt_hauls >> Bo[i - 45].Runs >> Bo[i - 45].Batting_strike_rate >> Bo[i - 45].Batting_average >> Bo[i - 45].Best_Batting_figure >> Bo[i - 45].Fours >> Bo[i - 45].Sixes;
    }
    for (int i = 98; i < 128; i++)
    {
        allrounder >> id[i] >> Ar[i - 98].First_name >> Ar[i - 98].Last_name >> Ar[i - 98].Age >> Ar[i - 98].Team >> Ar[i - 98].Country >> Ar[i - 98].No_of_matches >> Ar[i - 98].Innings >> Ar[i - 98].Runs >> Ar[i - 98].Batting_strike_rate >> Ar[i - 98].Batting_average >> Ar[i - 98].Fifties >> Ar[i - 98].Centuries >> Ar[i - 98].Best_Batting_figure >> Ar[i - 98].Fours >> Ar[i - 98].Sixes >> Ar[i - 98].Wickets >> Ar[i - 98].Economy >> Ar[i - 98].Bowling_average >> Ar[i - 98].Best_Bowling_figure >> Ar[i - 98].Four_wkt_hauls;
    }
    for (int i = 128; i < 136; i++)
    {
        wktkeeper >> id[i] >> Wk[i - 128].First_name >> Wk[i - 128].Last_name >> Wk[i - 128].Age >> Wk[i - 128].Team >> Wk[i - 128].Country >> Wk[i - 128].No_of_matches >> Wk[i - 128].Innings >> Wk[i - 128].Stumps >> Wk[i - 128].Catches >> Wk[i - 128].Runs >> Wk[i - 128].Batting_strike_rate >> Wk[i - 128].Batting_average >> Wk[i - 128].Fifties >> Wk[i - 128].Centuries >> Wk[i - 128].Best_Batting_figure >> Wk[i - 128].Fours >> Wk[i - 128].Sixes;
    }

    int runs[136];
    for (int i = 0; i < 45; i++)
        runs[i] = Bt[i].Runs;

    for (int i = 45; i < 98; i++)
        runs[i] = Bo[i - 45].Runs;

    for (int i = 98; i < 128; i++)
        runs[i] = Ar[i - 98].Runs;

    for (int i = 128; i < 136; i++)
        runs[i] = Wk[i - 128].Runs;

    int n = sizeof(runs) / sizeof(runs[0]);
    sort(runs, runs + n, greater<int>());

    int n1 = 136;
    for (int i = 0; i < n1; ++i)
    {
        for (int j = i + 1; j < n1;)
        {
            if (runs[i] == runs[j]) //checks for multiple instances of same runs
            {
                for (int k = j; k < n1 - 1; ++k)
                    runs[k] = runs[k + 1];
                --n1;
            }
            else
                ++j;
        }
    }

    cout << "SNo  F.Name     L.Name       TEAM                        TM   RUNS" << endl
         << endl
         << endl;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 45; j++)
        {
            if (runs[i] == Bt[j].Runs) // checks where the given (runs) occurs in the stat file
            {
                cout << left << setw(5) << id[i] << setw(11) << Bt[j].First_name << setw(13) << Bt[j].Last_name << setw(28) << Bt[j].Team << setw(5) << Bt[j].No_of_matches << setw(5) << Bt[j].Runs << endl;
                cout << "------------------------------------------------------------------" << endl;
            }
        }
        for (int j = 0; j < 53; j++)
        {
            if (runs[i] == Bo[j].Runs) // checks where the given (runs) occurs in the stat file
            {
                cout << left << setw(5) << id[i] << setw(11) << Bo[j].First_name << setw(13) << Bo[j].Last_name << setw(28) << Bo[j].Team << setw(5) << Bo[j].No_of_matches << setw(5) << Bo[j].Runs << endl;
                cout << "------------------------------------------------------------------" << endl;
            }
        }
        for (int j = 0; j < 30; j++)
        {
            if (runs[i] == Ar[j].Runs) // checks where the given (runs) occurs in the stat file
            {
                cout << left << setw(5) << id[i] << setw(11) << Ar[j].First_name << setw(13) << Ar[j].Last_name << setw(28) << Ar[j].Team << setw(5) << Ar[j].No_of_matches << setw(5) << Ar[j].Runs << endl;
                cout << "------------------------------------------------------------------" << endl;
            }
        }
        for (int j = 0; j < 8; j++)
        {
            if (runs[i] == Wk[j].Runs) // checks where the given (runs) occurs in the stat file
            {
                cout << left << setw(5) << id[i] << setw(11) << Wk[j].First_name << setw(13) << Wk[j].Last_name << setw(28) << Wk[j].Team << setw(5) << Wk[j].No_of_matches << setw(5) << Wk[j].Runs << endl;
                cout << "------------------------------------------------------------------" << endl;
            }
        }
    }
}
void Display_top10_strikerate(Batsman *Bt, All_rounder *Ar, Wicket_keeper *Wk)
{
    fstream bat("batsman.txt");
    if (!bat)
        cout << "Error opening the file!!" << endl;
    fstream allrounder("all_rounders.txt");
    if (!allrounder)
        cout << "Error opening the file!!" << endl;
    fstream wktkeeper("WICKETKEEPERS.txt");
    if (!wktkeeper)
        cout << "Error opening the file!!" << endl;

    int id[83];
    bat.seekg(0);
    allrounder.seekg(0);
    wktkeeper.seekg(0);

    for (int i = 0; i < 45; i++)
    {
        bat >> id[i] >> Bt[i].First_name >> Bt[i].Last_name >> Bt[i].Age >> Bt[i].Team >> Bt[i].Country >> Bt[i].No_of_matches >> Bt[i].Innings >> Bt[i].Runs >> Bt[i].Batting_strike_rate >> Bt[i].Batting_average >> Bt[i].Fifties >> Bt[i].Centuries >> Bt[i].Best_Batting_figure >> Bt[i].Fours >> Bt[i].Sixes;
    }
    for (int i = 45; i < 75; i++)
    {
        allrounder >> id[i] >> Ar[i - 45].First_name >> Ar[i - 45].Last_name >> Ar[i - 45].Age >> Ar[i - 45].Team >> Ar[i - 45].Country >> Ar[i - 45].No_of_matches >> Ar[i - 45].Innings >> Ar[i - 45].Runs >> Ar[i - 45].Batting_strike_rate >> Ar[i - 45].Batting_average >> Ar[i - 45].Fifties >> Ar[i - 45].Centuries >> Ar[i - 45].Best_Batting_figure >> Ar[i - 45].Fours >> Ar[i - 45].Sixes >> Ar[i - 45].Wickets >> Ar[i - 45].Economy >> Ar[i - 45].Bowling_average >> Ar[i - 45].Best_Bowling_figure >> Ar[i - 45].Four_wkt_hauls;
    }
    for (int i = 75; i < 83; i++)
    {
        wktkeeper >> id[i] >> Wk[i - 75].First_name >> Wk[i - 75].Last_name >> Wk[i - 75].Age >> Wk[i - 75].Team >> Wk[i - 75].Country >> Wk[i - 75].No_of_matches >> Wk[i - 75].Innings >> Wk[i - 75].Stumps >> Wk[i - 75].Catches >> Wk[i - 75].Runs >> Wk[i - 75].Batting_strike_rate >> Wk[i - 75].Batting_average >> Wk[i - 75].Fifties >> Wk[i - 75].Centuries >> Wk[i - 75].Best_Batting_figure >> Wk[i - 75].Fours >> Wk[i - 75].Sixes;
    }

    float strike_rate[83];
    for (int i = 0; i < 45; i++)
        strike_rate[i] = Bt[i].Batting_strike_rate;

    for (int i = 45; i < 75; i++)
        strike_rate[i] = Ar[i - 45].Batting_strike_rate;

    for (int i = 75; i < 83; i++)
        strike_rate[i] = Wk[i - 75].Batting_strike_rate;

    int n = sizeof(strike_rate) / sizeof(strike_rate[0]);
    sort(strike_rate, strike_rate + n, greater<int>());

    int n1 = 83;
    for (int i = 0; i < n1; ++i)
    {
        for (int j = i + 1; j < n1;)
        {
            if (strike_rate[i] == strike_rate[j]) //checks for multiple instances of same runs
            {
                for (int k = j; k < n1 - 1; ++k)
                    strike_rate[k] = strike_rate[k + 1];
                --n1;
            }
            else
                ++j;
        }
    }
    cout << "SNo  F.Name     L.Name       TEAM                        TM   St Rate" << endl
         << endl
         << endl;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 45; j++)
        {
            if (strike_rate[i] == Bt[j].Batting_strike_rate) // checks where the given (strike_rate) occurs in the stat file
            {
                cout << left << setw(5) << id[i] << setw(11) << Bt[j].First_name << setw(13) << Bt[j].Last_name << setw(28) << Bt[j].Team << setw(5) << Bt[j].No_of_matches << setw(5) << Bt[j].Batting_strike_rate << endl;
                cout << "---------------------------------------------------------------------" << endl;
            }
        }
        for (int j = 0; j < 30; j++)
        {
            if (strike_rate[i] == Ar[j].Batting_strike_rate) // checks where the given (strike_rate) occurs in the stat file
            {
                cout << left << setw(5) << id[i] << setw(11) << Ar[j].First_name << setw(13) << Ar[j].Last_name << setw(28) << Ar[j].Team << setw(5) << Ar[j].No_of_matches << setw(5) << Ar[j].Batting_strike_rate << endl;
                cout << "---------------------------------------------------------------------" << endl;
            }
        }
        for (int j = 0; j < 8; j++)
        {
            if (strike_rate[i] == Wk[j].Batting_strike_rate) // checks where the given (strike_rate) occurs in the stat file
            {
                cout << left << setw(5) << id[i] << setw(11) << Wk[j].First_name << setw(13) << Wk[j].Last_name << setw(28) << Wk[j].Team << setw(5) << Wk[j].No_of_matches << setw(5) << Wk[j].Batting_strike_rate << endl;
                cout << "---------------------------------------------------------------------" << endl;
            }
        }
    }
}
void Display_top10_batavg(Batsman *Bt, All_rounder *Ar, Wicket_keeper *Wk)
{
    fstream bat("batsman.txt");
    if (!bat)
        cout << "Error opening the file!!" << endl;
    fstream allrounder("all_rounders.txt");
    if (!allrounder)
        cout << "Error opening the file!!" << endl;
    fstream wktkeeper("WICKETKEEPERS.txt");
    if (!wktkeeper)
        cout << "Error opening the file!!" << endl;

    int id[83];
    bat.seekg(0);
    allrounder.seekg(0);
    wktkeeper.seekg(0);

    for (int i = 0; i < 45; i++)
    {
        bat >> id[i] >> Bt[i].First_name >> Bt[i].Last_name >> Bt[i].Age >> Bt[i].Team >> Bt[i].Country >> Bt[i].No_of_matches >> Bt[i].Innings >> Bt[i].Runs >> Bt[i].Batting_strike_rate >> Bt[i].Batting_average >> Bt[i].Fifties >> Bt[i].Centuries >> Bt[i].Best_Batting_figure >> Bt[i].Fours >> Bt[i].Sixes;
    }
    for (int i = 45; i < 75; i++)
    {
        allrounder >> id[i] >> Ar[i - 45].First_name >> Ar[i - 45].Last_name >> Ar[i - 45].Age >> Ar[i - 45].Team >> Ar[i - 45].Country >> Ar[i - 45].No_of_matches >> Ar[i - 45].Innings >> Ar[i - 45].Runs >> Ar[i - 45].Batting_strike_rate >> Ar[i - 45].Batting_average >> Ar[i - 45].Fifties >> Ar[i - 45].Centuries >> Ar[i - 45].Best_Batting_figure >> Ar[i - 45].Fours >> Ar[i - 45].Sixes >> Ar[i - 45].Wickets >> Ar[i - 45].Economy >> Ar[i - 45].Bowling_average >> Ar[i - 45].Best_Bowling_figure >> Ar[i - 45].Four_wkt_hauls;
    }
    for (int i = 75; i < 83; i++)
    {
        wktkeeper >> id[i] >> Wk[i - 75].First_name >> Wk[i - 75].Last_name >> Wk[i - 75].Age >> Wk[i - 75].Team >> Wk[i - 75].Country >> Wk[i - 75].No_of_matches >> Wk[i - 75].Innings >> Wk[i - 75].Stumps >> Wk[i - 75].Catches >> Wk[i - 75].Runs >> Wk[i - 75].Batting_strike_rate >> Wk[i - 75].Batting_average >> Wk[i - 75].Fifties >> Wk[i - 75].Centuries >> Wk[i - 75].Best_Batting_figure >> Wk[i - 75].Fours >> Wk[i - 75].Sixes;
    }

    float batavg[83];
    for (int i = 0; i < 45; i++)
        batavg[i] = Bt[i].Batting_average;

    for (int i = 45; i < 75; i++)
        batavg[i] = Ar[i - 45].Batting_average;

    for (int i = 75; i < 83; i++)
        batavg[i] = Wk[i - 75].Batting_average;

    int n = sizeof(batavg) / sizeof(batavg[0]);
    sort(batavg, batavg + n, greater<int>());

    int n1 = 83;
    for (int i = 0; i < n1; ++i)
    {
        for (int j = i + 1; j < n1;)
        {
            if (batavg[i] == batavg[j]) //checks for multiple instances of same runs
            {
                for (int k = j; k < n1 - 1; ++k)
                    batavg[k] = batavg[k + 1];
                --n1;
            }
            else
                ++j;
        }
    }

    cout << "SNo  F.Name     L.Name       TEAM                        TM   Bat Avg" << endl
         << endl
         << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 45; j++)
        {
            if (batavg[i] == Bt[j].Batting_average) // checks where the given (batavg) occurs in the stat file
            {
                cout << left << setw(5) << id[i] << setw(11) << Bt[j].First_name << setw(13) << Bt[j].Last_name << setw(28) << Bt[j].Team << setw(5) << Bt[j].No_of_matches << setw(5) << Bt[j].Batting_average << endl;
                cout << "---------------------------------------------------------------------" << endl;
            }
        }
        for (int j = 0; j < 30; j++)
        {
            if (batavg[i] == Ar[j].Batting_average) // checks where the given (batavg) occurs in the stat file
            {
                cout << left << setw(5) << id[i] << setw(11) << Ar[j].First_name << setw(13) << Ar[j].Last_name << setw(28) << Ar[j].Team << setw(5) << Ar[j].No_of_matches << setw(5) << Ar[j].Batting_average << endl;
                cout << "---------------------------------------------------------------------" << endl;
            }
        }
        for (int j = 0; j < 8; j++)
        {
            if (batavg[i] == Wk[j].Batting_average) // checks where the given (batavg) occurs in the stat file
            {
                cout << left << setw(5) << id[i] << setw(11) << Wk[j].First_name << setw(13) << Wk[j].Last_name << setw(28) << Wk[j].Team << setw(5) << Wk[j].No_of_matches << setw(5) << Wk[j].Batting_average << endl;
                cout << "---------------------------------------------------------------------" << endl;
            }
        }
    }
}
void Display_top10_wkt(Bowler *Bo, All_rounder *Ar)
{
    fstream bowl("bowlers.txt");
    if (!bowl)
        cout << "Error opening the file!!" << endl;
    fstream allrounder("all_rounders.txt");
    if (!allrounder)
        cout << "Error opening the file!!" << endl;

    int id[83];
    bowl.seekg(0);
    allrounder.seekg(0);

    for (int i = 0; i < 53; i++)
    {
        bowl >> id[i] >> Bo[i].First_name >> Bo[i].Last_name >> Bo[i].Age >> Bo[i].Team >> Bo[i].Country >> Bo[i].No_of_matches >> Bo[i].Innings >> Bo[i].Wickets >> Bo[i].Economy >> Bo[i].Bowling_average >> Bo[i].Best_Bowling_figure >> Bo[i].Four_wkt_hauls >> Bo[i].Runs >> Bo[i].Batting_strike_rate >> Bo[i].Batting_average >> Bo[i].Best_Batting_figure >> Bo[i].Fours >> Bo[i].Sixes;
    }
    for (int i = 53; i < 83; i++)
    {
        allrounder >> id[i] >> Ar[i - 53].First_name >> Ar[i - 53].Last_name >> Ar[i - 53].Age >> Ar[i - 53].Team >> Ar[i - 53].Country >> Ar[i - 53].No_of_matches >> Ar[i - 53].Innings >> Ar[i - 53].Runs >> Ar[i - 53].Batting_strike_rate >> Ar[i - 53].Batting_average >> Ar[i - 53].Fifties >> Ar[i - 53].Centuries >> Ar[i - 53].Best_Batting_figure >> Ar[i - 53].Fours >> Ar[i - 53].Sixes >> Ar[i - 53].Wickets >> Ar[i - 53].Economy >> Ar[i - 53].Bowling_average >> Ar[i - 53].Best_Bowling_figure >> Ar[i - 53].Four_wkt_hauls;
    }

    int wkts[83];
    for (int i = 0; i < 53; i++)
        wkts[i] = Bo[i].Wickets;

    for (int i = 53; i < 83; i++)
        wkts[i] = Ar[i - 53].Wickets;

    int n = sizeof(wkts) / sizeof(wkts[0]);
    sort(wkts, wkts + n, greater<int>());

    int n1 = 83;
    for (int i = 0; i < n1; ++i)
    {
        for (int j = i + 1; j < n1;)
        {
            if (wkts[i] == wkts[j]) //checks for multiple instances of same runs
            {
                for (int k = j; k < n1 - 1; ++k)
                    wkts[k] = wkts[k + 1];
                --n1;
            }
            else
                ++j;
        }
    }

    cout << "SNo  F.Name     L.Name       TEAM                        TM    Wkt" << endl
         << endl
         << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 53; j++)
        {
            if (wkts[i] == Bo[j].Wickets) // checks where the given (wkts) occurs in the stat file
            {
                cout << left << setw(5) << id[i] << setw(11) << Bo[j].First_name << setw(14) << Bo[j].Last_name << setw(28) << Bo[j].Team << setw(5) << Bo[j].No_of_matches << setw(5) << Bo[j].Wickets << endl;
                cout << "------------------------------------------------------------------" << endl;
            }
        }
        for (int j = 0; j < 30; j++)
        {
            if (wkts[i] == Ar[j].Wickets) // checks where the given (wkts) occurs in the stat file
            {
                cout << left << setw(5) << id[i] << setw(11) << Ar[j].First_name << setw(14) << Ar[j].Last_name << setw(28) << Ar[j].Team << setw(5) << Ar[j].No_of_matches << setw(5) << Ar[j].Wickets << endl;
                cout << "------------------------------------------------------------------" << endl;
            }
        }
    }
}
void Display_top10_bowlavg(Bowler *Bo, All_rounder *Ar)
{
    fstream bowl("bowlers.txt");
    if (!bowl)
        cout << "Error opening the file!!" << endl;
    fstream allrounder("all_rounders.txt");
    if (!allrounder)
        cout << "Error opening the file!!" << endl;

    int id[83];
    bowl.seekg(0);
    allrounder.seekg(0);

    for (int i = 0; i < 53; i++)
    {
        bowl >> id[i] >> Bo[i].First_name >> Bo[i].Last_name >> Bo[i].Age >> Bo[i].Team >> Bo[i].Country >> Bo[i].No_of_matches >> Bo[i].Innings >> Bo[i].Wickets >> Bo[i].Economy >> Bo[i].Bowling_average >> Bo[i].Best_Bowling_figure >> Bo[i].Four_wkt_hauls >> Bo[i].Runs >> Bo[i].Batting_strike_rate >> Bo[i].Batting_average >> Bo[i].Best_Batting_figure >> Bo[i].Fours >> Bo[i].Sixes;
    }
    for (int i = 53; i < 83; i++)
    {
        allrounder >> id[i] >> Ar[i - 53].First_name >> Ar[i - 53].Last_name >> Ar[i - 53].Age >> Ar[i - 53].Team >> Ar[i - 53].Country >> Ar[i - 53].No_of_matches >> Ar[i - 53].Innings >> Ar[i - 53].Runs >> Ar[i - 53].Batting_strike_rate >> Ar[i - 53].Batting_average >> Ar[i - 53].Fifties >> Ar[i - 53].Centuries >> Ar[i - 53].Best_Batting_figure >> Ar[i - 53].Fours >> Ar[i - 53].Sixes >> Ar[i - 53].Wickets >> Ar[i - 53].Economy >> Ar[i - 53].Bowling_average >> Ar[i - 53].Best_Bowling_figure >> Ar[i - 53].Four_wkt_hauls;
    }

    float bowlavg[83];
    for (int i = 0; i < 53; i++)
        bowlavg[i] = Bo[i].Bowling_average;

    for (int i = 53; i < 83; i++)
        bowlavg[i] = Ar[i - 53].Bowling_average;

    int tot = 83;
    for (int i = 0; i < tot; i++)
    {
        if (bowlavg[i] == 0)
        {
            for (int j = i; j < (tot - 1); j++)
                bowlavg[j] = bowlavg[j + 1];
            i--;
            tot--;
        }
    }

    int n = sizeof(bowlavg) / sizeof(bowlavg[0]);
    sort(bowlavg, bowlavg + n);

    int n1 = 83;
    for (int i = 0; i < n1; ++i)
    {
        for (int j = i + 1; j < n1;)
        {
            if (bowlavg[i] == bowlavg[j]) //checks for multiple instances of same runs
            {
                for (int k = j; k < n1 - 1; ++k)
                    bowlavg[k] = bowlavg[k + 1];
                --n1;
            }
            else
                ++j;
        }
    }

    cout << "SNo  F.Name     L.Name       TEAM                        TM    Bowl Avg" << endl
         << endl
         << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 53; j++)
        {
            if (bowlavg[i] == Bo[j].Bowling_average) // checks where the given (bowlavg) occurs in the stat file
            {
                cout << left << setw(5) << id[i] << setw(11) << Bo[j].First_name << setw(14) << Bo[j].Last_name << setw(28) << Bo[j].Team << setw(5) << Bo[j].No_of_matches << setw(5) << Bo[j].Bowling_average << endl;
                cout << "-----------------------------------------------------------------------" << endl;
            }
        }
        for (int j = 0; j < 30; j++)
        {
            if (bowlavg[i] == Ar[j].Bowling_average) // checks where the given (bowlavg) occurs in the stat file
            {
                cout << left << setw(5) << id[i] << setw(11) << Ar[j].First_name << setw(14) << Ar[j].Last_name << setw(28) << Ar[j].Team << setw(5) << Ar[j].No_of_matches << setw(5) << Ar[j].Bowling_average << endl;
                cout << "-----------------------------------------------------------------------" << endl;
            }
        }
    }
}
void Display_top10_eco(Bowler *Bo, All_rounder *Ar)
{
    fstream bowl("bowlers.txt");
    if (!bowl)
        cout << "Error opening the file!!" << endl;
    fstream allrounder("all_rounders.txt");
    if (!allrounder)
        cout << "Error opening the file!!" << endl;

    int id[83];
    bowl.seekg(0);
    allrounder.seekg(0);

    for (int i = 0; i < 53; i++)
    {
        bowl >> id[i] >> Bo[i].First_name >> Bo[i].Last_name >> Bo[i].Age >> Bo[i].Team >> Bo[i].Country >> Bo[i].No_of_matches >> Bo[i].Innings >> Bo[i].Wickets >> Bo[i].Economy >> Bo[i].Bowling_average >> Bo[i].Best_Bowling_figure >> Bo[i].Four_wkt_hauls >> Bo[i].Runs >> Bo[i].Batting_strike_rate >> Bo[i].Batting_average >> Bo[i].Best_Batting_figure >> Bo[i].Fours >> Bo[i].Sixes;
    }
    for (int i = 53; i < 83; i++)
    {
        allrounder >> id[i] >> Ar[i - 53].First_name >> Ar[i - 53].Last_name >> Ar[i - 53].Age >> Ar[i - 53].Team >> Ar[i - 53].Country >> Ar[i - 53].No_of_matches >> Ar[i - 53].Innings >> Ar[i - 53].Runs >> Ar[i - 53].Batting_strike_rate >> Ar[i - 53].Batting_average >> Ar[i - 53].Fifties >> Ar[i - 53].Centuries >> Ar[i - 53].Best_Batting_figure >> Ar[i - 53].Fours >> Ar[i - 53].Sixes >> Ar[i - 53].Wickets >> Ar[i - 53].Economy >> Ar[i - 53].Bowling_average >> Ar[i - 53].Best_Bowling_figure >> Ar[i - 53].Four_wkt_hauls;
    }

    float eco[83];
    for (int i = 0; i < 53; i++)
        eco[i] = Bo[i].Economy;

    for (int i = 53; i < 83; i++)
        eco[i] = Ar[i - 53].Economy;

    int tot = 83;
    for (int i = 0; i < tot; i++)
    {
        if (eco[i] == 0)
        {
            for (int j = i; j < (tot - 1); j++)
                eco[j] = eco[j + 1];
            i--;
            tot--;
        }
    }

    int n = sizeof(eco) / sizeof(eco[0]);
    sort(eco, eco + n);

    int n1 = 83;
    for (int i = 0; i < n1; ++i)
    {
        for (int j = i + 1; j < n1;)
        {
            if (eco[i] == eco[j]) //checks for multiple instances of same runs
            {
                for (int k = j; k < n1 - 1; ++k)
                    eco[k] = eco[k + 1];
                --n1;
            }
            else
                ++j;
        }
    }

    cout << "SNo  F.Name     L.Name       TEAM                        TM    Eco" << endl
         << endl
         << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 53; j++)
        {
            if (eco[i] == Bo[j].Economy) // checks where the given (eco) occurs in the stat file
            {
                cout << left << setw(5) << id[i] << setw(11) << Bo[j].First_name << setw(14) << Bo[j].Last_name << setw(28) << Bo[j].Team << setw(5) << Bo[j].No_of_matches << setw(5) << Bo[j].Economy << endl;
                cout << "--------------------------------------------------------------------" << endl;
            }
        }
        for (int j = 0; j < 30; j++)
        {
            if (eco[i] == Ar[j].Economy) // checks where the given (eco) occurs in the stat file
            {
                cout << left << setw(5) << id[i] << setw(11) << Ar[j].First_name << setw(14) << Ar[j].Last_name << setw(28) << Ar[j].Team << setw(5) << Ar[j].No_of_matches << setw(5) << Ar[j].Economy << endl;
                cout << "--------------------------------------------------------------------" << endl;
            }
        }
    }
}
void Display_top10_goal(Attack *A, MidField *Mf, Defence *D)
{
    fstream forward("attack.txt");
    if (!forward)
        cout << "Error opening the file!!" << endl;
    fstream midf("midfield.txt");
    if (!midf)
        cout << "Error opening the file!!" << endl;
    fstream defence("DEFENDERS.txt");
    if (!defence)
        cout << "Error opening the file!!" << endl;

    forward.seekg(0);
    midf.seekg(0);
    defence.seekg(0);

    int id[276];
    int _id = 1;
    for (int i = 0; i < 276; i++)
    {
        id[i] = _id;
        _id++;
    }

    for (int i = 0; i < 58; i++)
    {
        forward >> A[i].First_name >> A[i].Last_name >> A[i].Position >> A[i].Age >> A[i].Team >> A[i].Country >> A[i].No_of_matches >> A[i].Goals >> A[i].Shot_accuracy >> A[i].Assist >> A[i].Pass_Accuracy >> A[i].Red_card;
    }
    for (int i = 58; i < 169; i++)
    {
        midf >> Mf[i - 58].First_name >> Mf[i - 58].Last_name >> Mf[i - 58].Position >> Mf[i - 58].Age >> Mf[i - 58].Team >> Mf[i - 58].Country >> Mf[i - 58].No_of_matches >> Mf[i - 58].Goals >> Mf[i - 58].Shot_accuracy >> Mf[i - 58].Assist >> Mf[i - 58].Pass_Accuracy >> Mf[i - 58].Red_card;
    }
    for (int i = 169; i < 276; i++)
    {
        defence >> D[i - 169].First_name >> D[i - 169].Last_name >> D[i - 169].Position >> D[i - 169].Age >> D[i - 169].Team >> D[i - 169].Country >> D[i - 169].No_of_matches >> D[i - 169].Tackles_won >> D[i - 169].Clearance >> D[i - 169].Blocked_shots >> D[i - 169].Red_card >> D[i - 169].Goals >> D[i - 169].Pass_Accuracy;
    }
    int goalrt[276];
    for (int i = 0; i < 58; i++)
        goalrt[i] = A[i].Goals;

    for (int i = 58; i < 169; i++)
        goalrt[i] = Mf[i - 58].Goals;

    for (int i = 169; i < 276; i++)
        goalrt[i] = D[i - 169].Goals;

    int n = sizeof(goalrt) / sizeof(goalrt[0]);
    sort(goalrt, goalrt + n, greater<int>());

    int n1 = 276;
    for (int i = 0; i < n1; ++i)
    {
        for (int j = i + 1; j < n1;)
        {
            if (goalrt[i] == goalrt[j]) //checks for multiple instances of same goals
            {
                for (int k = j; k < n1 - 1; ++k)
                    goalrt[k] = goalrt[k + 1];
                --n1;
            }
            else
                ++j;
        }
    }

    cout << "SNo Name                    Pos  Age Club                  Country      GP   Goals" << endl
         << endl;
    int check = 1;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 58; j++)
        {
            if (goalrt[i] == A[j].Goals && check <= 10) // checks where the given (goals) occurs in the stat file
            {
                check++;
                cout << left << setw(4) << id[i] << setw(10) << A[j].First_name << setw(14) << A[j].Last_name << setw(5) << A[j].Position << setw(4) << A[j].Age << setw(22) << A[j].Team << setw(13) << A[j].Country << setw(5) << A[j].No_of_matches << setw(6) << A[j].Goals << endl;
                cout << "----------------------------------------------------------------------------------" << endl;
            }
        }
        for (int j = 0; j < 111; j++)
        {
            if (goalrt[i] == Mf[j].Goals && check <= 10) // checks where the given (goals) occurs in the stat file
            {
                check++;
                cout << left << setw(4) << id[i] << setw(10) << Mf[j].First_name << setw(14) << Mf[j].Last_name << setw(5) << Mf[j].Position << setw(4) << Mf[j].Age << setw(22) << Mf[j].Team << setw(13) << Mf[j].Country << setw(5) << Mf[j].No_of_matches << setw(6) << Mf[j].Goals << endl;
                cout << "----------------------------------------------------------------------------------" << endl;
            }
        }
        for (int j = 0; j < 107; j++)
        {
            if (goalrt[i] == D[j].Goals && check <= 10) // checks where the given (goals) occurs in the stat file
            {
                check++;
                cout << left << setw(4) << id[i] << setw(10) << D[j].First_name << setw(14) << D[j].Last_name << setw(5) << D[j].Position << setw(4) << D[j].Age << setw(22) << D[j].Team << setw(13) << D[j].Country << setw(5) << D[j].No_of_matches << setw(7) << D[j].Goals << endl;
                cout << "-----------------------------------------------------------------------------------" << endl;
            }
        }
    }
}
void Display_top10_cleansheet(GoalKeeper *Gk)
{
    fstream gk("gk.txt");
    if (!gk)
        cout << "Error opening the file!!" << endl;

    gk.seekg(0);

    int id[27];
    int _id = 1;
    for (int i = 0; i < 27; i++)
    {
        id[i] = _id;
        _id++;
    }

    for (int i = 0; i < 27; i++)
    {
        gk >> Gk[i].First_name >> Gk[i].Last_name >> Gk[i].Position >> Gk[i].Age >> Gk[i].Team >> Gk[i].Country >> Gk[i].No_of_matches >> Gk[i].Clean_sheets >> Gk[i].Saves_made >> Gk[i].Goals_conceeded >> Gk[i].Red_card;
    }

    int cs[27];
    for (int i = 0; i < 27; i++)
        cs[i] = Gk[i].Clean_sheets;

    int n = sizeof(cs) / sizeof(cs[0]);
    sort(cs, cs + n, greater<int>());

    int n1 = 27;
    for (int i = 0; i < n1; ++i)
    {
        for (int j = i + 1; j < n1;)
        {
            if (cs[i] == cs[j]) //checks for multiple instances of same goals
            {
                for (int k = j; k < n1 - 1; ++k)
                    cs[k] = cs[k + 1];
                --n1;
            }
            else
                ++j;
        }
    }

    cout << "SNo Name                    Pos  Age Club                  Country      GP   C.Sheet" << endl
         << endl;

    int check = 1;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 58; j++)
        {
            if (cs[i] == Gk[j].Clean_sheets && check <= 10) // checks where the given (cleansheet) occurs in the stat file
            {
                check++;
                cout << left << setw(4) << id[i] << setw(10) << Gk[j].First_name << setw(14) << Gk[j].Last_name << setw(5) << Gk[j].Position << setw(4) << Gk[j].Age << setw(22) << Gk[j].Team << setw(13) << Gk[j].Country << setw(5) << Gk[j].No_of_matches << setw(6) << Gk[j].Clean_sheets << endl;
                cout << "------------------------------------------------------------------------------------" << endl;
            }
        }
    }
}
void Display_top10_assist(Attack *A, MidField *Mf)
{
    fstream forward("attack.txt");
    if (!forward)
        cout << "Error opening the file!!" << endl;
    fstream midf("midfield.txt");
    if (!midf)
        cout << "Error opening the file!!" << endl;

    forward.seekg(0);
    midf.seekg(0);

    int id[169];
    int _id = 1;
    for (int i = 0; i < 169; i++)
    {
        id[i] = _id;
        _id++;
    }

    for (int i = 0; i < 58; i++)
    {
        forward >> A[i].First_name >> A[i].Last_name >> A[i].Position >> A[i].Age >> A[i].Team >> A[i].Country >> A[i].No_of_matches >> A[i].Goals >> A[i].Shot_accuracy >> A[i].Assist >> A[i].Pass_Accuracy >> A[i].Red_card;
    }
    for (int i = 58; i < 169; i++)
    {
        midf >> Mf[i - 58].First_name >> Mf[i - 58].Last_name >> Mf[i - 58].Position >> Mf[i - 58].Age >> Mf[i - 58].Team >> Mf[i - 58].Country >> Mf[i - 58].No_of_matches >> Mf[i - 58].Goals >> Mf[i - 58].Shot_accuracy >> Mf[i - 58].Assist >> Mf[i - 58].Pass_Accuracy >> Mf[i - 58].Red_card;
    }

    int assrt[169];
    for (int i = 0; i < 58; i++)
        assrt[i] = A[i].Assist;

    for (int i = 58; i < 169; i++)
        assrt[i] = Mf[i - 58].Assist;

    int n = sizeof(assrt) / sizeof(assrt[0]);
    sort(assrt, assrt + n, greater<int>());

    int n1 = 169;
    for (int i = 0; i < n1; ++i)
    {
        for (int j = i + 1; j < n1;)
        {
            if (assrt[i] == assrt[j]) //checks for multiple instances of same goals
            {
                for (int k = j; k < n1 - 1; ++k)
                    assrt[k] = assrt[k + 1];
                --n1;
            }
            else
                ++j;
        }
    }

    cout << "SNo Name                    Pos  Age Club                  Country      GP   Assist" << endl
         << endl;

    int check = 1;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 58; j++)
        {
            if (assrt[i] == A[j].Assist && check <= 10) // checks where the given (assist) occurs in the stat file
            {
                check++;
                cout << left << setw(4) << id[i] << setw(10) << A[j].First_name << setw(14) << A[j].Last_name << setw(5) << A[j].Position << setw(4) << A[j].Age << setw(22) << A[j].Team << setw(13) << A[j].Country << setw(5) << A[j].No_of_matches << setw(6) << A[j].Assist << endl;
                cout << "-----------------------------------------------------------------------------------" << endl;
            }
        }
        for (int j = 0; j < 111; j++)
        {
            if (assrt[i] == Mf[j].Assist && check <= 10) // checks where the given (assist) occurs in the stat file
            {
                check++;
                cout << left << setw(4) << id[i] << setw(10) << Mf[j].First_name << setw(14) << Mf[j].Last_name << setw(5) << Mf[j].Position << setw(4) << Mf[j].Age << setw(22) << Mf[j].Team << setw(13) << Mf[j].Country << setw(5) << Mf[j].No_of_matches << setw(6) << Mf[j].Assist << endl;
                cout << "-----------------------------------------------------------------------------------" << endl;
            }
        }
    }
}
void Display_top10_defenders(Defence *D)
{

    fstream defence("DEFENDERS.txt");
    if (!defence)
        cout << "Error opening the file!!" << endl;

    defence.seekg(0);

    int id[107];
    int _id = 1;
    for (int i = 0; i < 107; i++)
    {
        id[i] = _id;
        _id++;
    }

    for (int i = 0; i < 107; i++)
    {
        defence >> D[i].First_name >> D[i].Last_name >> D[i].Position >> D[i].Age >> D[i].Team >> D[i].Country >> D[i].No_of_matches >> D[i].Tackles_won >> D[i].Clearance >> D[i].Blocked_shots >> D[i].Red_card >> D[i].Goals >> D[i].Pass_Accuracy;
    }
    int clrt[107];
    for (int i = 0; i < 107; i++)
        clrt[i] = D[i].Clearance;

    int n = sizeof(clrt) / sizeof(clrt[0]);
    sort(clrt, clrt + n, greater<int>());

    int n1 = 107;
    for (int i = 0; i < n1; ++i)
    {
        for (int j = i + 1; j < n1;)
        {
            if (clrt[i] == clrt[j]) //checks for multiple instances of same goals
            {
                for (int k = j; k < n1 - 1; ++k)
                    clrt[k] = clrt[k + 1];
                --n1;
            }
            else
                ++j;
        }
    }

    cout << "SNo Name                    Pos  Age Club                  Country      GP   Clearance" << endl
         << endl;

    int check = 1;
    for (int i = 0; i < 10; i++)
    {

        for (int j = 0; j < 107; j++)
        {
            if (clrt[i] == D[j].Clearance && check <= 10) // checks where the given (clearance) occurs in the stat file
            {
                check++;
                cout << left << setw(4) << id[i] << setw(10) << D[j].First_name << setw(14) << D[j].Last_name << setw(5) << D[j].Position << setw(4) << D[j].Age << setw(22) << D[j].Team << setw(13) << D[j].Country << setw(5) << D[j].No_of_matches << setw(7) << D[j].Clearance << endl;
                cout << "--------------------------------------------------------------------------------------" << endl;
            }
        }
    }
}
void Display_top10_leastgoal(GoalKeeper *Gk)
{
    fstream gk("gk.txt");
    if (!gk)
        cout << "Error opening the file!!" << endl;

    gk.seekg(0);

    int id[27];
    int _id = 1;
    for (int i = 0; i < 27; i++)
    {
        id[i] = _id;
        _id++;
    }

    for (int i = 0; i < 27; i++)
    {
        gk >> Gk[i].First_name >> Gk[i].Last_name >> Gk[i].Position >> Gk[i].Age >> Gk[i].Team >> Gk[i].Country >> Gk[i].No_of_matches >> Gk[i].Clean_sheets >> Gk[i].Saves_made >> Gk[i].Goals_conceeded >> Gk[i].Red_card;
    }

    int gc[27];
    for (int i = 0; i < 27; i++)
        gc[i] = Gk[i].Goals_conceeded;

    int tot = 83;
    for (int i = 0; i < tot; i++)
    {
        if (gc[i] == 0)
        {
            for (int j = i; j < (tot - 1); j++)
                gc[j] = gc[j + 1];
            i--;
            tot--;
        }
    }

    int n = sizeof(gc) / sizeof(gc[0]);
    sort(gc, gc + n);

    int n1 = 27;
    for (int i = 0; i < n1; ++i)
    {
        for (int j = i + 1; j < n1;)
        {
            if (gc[i] == gc[j]) //checks for multiple instances of same goals
            {
                for (int k = j; k < n1 - 1; ++k)
                    gc[k] = gc[k + 1];
                --n1;
            }
            else
                ++j;
        }
    }

    cout << "SNo Name                    Pos  Age Club                  Country      GP   Goal Conceeded" << endl
         << endl;

    int check = 1;
    int s_no = 1;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 58; j++)
        {
            if (gc[i] == Gk[j].Goals_conceeded && check <= 10) // checks where the given (gc) occurs in the stat file
            {
                check++;
                cout << left << setw(4) << s_no << setw(10) << Gk[j].First_name << setw(14) << Gk[j].Last_name << setw(5) << Gk[j].Position << setw(4) << Gk[j].Age << setw(22) << Gk[j].Team << setw(13) << Gk[j].Country << setw(5) << Gk[j].No_of_matches << setw(5) << Gk[j].Goals_conceeded << endl;
                cout << "-------------------------------------------------------------------------------------------" << endl;
                s_no++;
            }
        }
    }
}

//Main function of the program
int main()
{
    system("COLOR 06");
    Sports S; //Object declaration for the Sports
    Football F[500];
    Attack A[100];
    MidField Mf[120];
    Defence D[120];
    GoalKeeper Gk[100];
    Basketball B[500];
    Cricket C[200];
    Batsman Bt[50];
    Bowler Bo[60];
    All_rounder Ar[50];
    Wicket_keeper Wk[10];

start: //Goto point for the Main Menu
    system("cls");
    S.Main_Display();

    int num;
    cin >> num; //Main menu choice input
    system("cls");

    if (num == 1)
    {
    checkpoint_1: // Go-to point for Main menu of football
        F->Display_content_f();
        int switch_f; //For selecting options for football
        cin >> switch_f;
        system("cls");

        switch (switch_f)
        {
        case 1:
            F->Team_display_f();
            system("pause");
            system("cls");
            goto checkpoint_1; // returns to main content selection menu of football

        checkpoint_1_1:
        case 2:
            cout << "                                      >>>>>> Welcome to Football <<<<<<" << endl
                 << endl;
            cout << "                                      X--------- View Players --------X" << endl
                 << endl;
            cout << "                                      1. Search Player " << endl
                 << "                                      2. View All Players " << endl
                 << "                                      3. Return to Main Menu" << endl
                 << "                                      0. Exit the program " << endl
                 << endl;
            cout << "                                      Enter your choice: ";

            int player;
            cin >> player;
            system("cls");
            if (player == 1)
            {
            checkpoint_1_1_1:
                cout << "                                      1. Forward" << endl
                     << "                                      2. Mid-Fielder" << endl
                     << "                                      3. Defender " << endl
                     << "                                      4. Goal-Keeper" << endl
                     << "                                      5. Return to Main Menu" << endl
                     << endl;
                cout << "                                      Enter your choice: ";

                int category;
                cin >> category;
                system("cls");
                string name;

                switch (category)
                {
                case 1:
                    cout << "Enter name of the player to search : ";
                    cin >> name;
                    A->Search_player_f_a(A, name);
                    system("pause");
                    system("cls");
                    goto checkpoint_1_1_1;
                    break;
                case 2:
                    cout << "Enter name of the player to search : ";
                    cin >> name;
                    Mf->Search_player_f_m(Mf, name);
                    system("pause");
                    system("cls");
                    goto checkpoint_1_1_1;
                    break;
                case 3:
                    cout << "Enter name of the player to search : ";
                    cin >> name;
                    D->Search_player_f_d(D, name);
                    system("pause");
                    system("cls");
                    goto checkpoint_1_1_1;
                    break;
                case 4:
                    cout << "Enter name of the player to search : ";
                    cin >> name;
                    Gk->Search_player_f_gk(Gk, name);
                    system("pause");
                    system("cls");
                    goto checkpoint_1_1_1;
                    break;
                case 5:
                    system("cls");
                    goto checkpoint_1_1;
                    break;
                default:
                    cout << "No such option available! Please try again!" << endl;
                    system("pause");
                    system("cls");
                    goto checkpoint_1_1_1;
                    break;
                }
                system("pause");
                system("cls");
                goto checkpoint_1_1; // returns to player menu of football
            }
            else if (player == 2)
            {
                A->Player_display_f_a(A);
                Mf->Player_display_f_m(Mf);
                D->Player_display_f_d(D);
                Gk->Player_display_f_gk(Gk);
                system("pause");
                system("cls");
                goto checkpoint_1_1; // returns to player menu of football
            }
            else if (player == 3)
            {
                system("cls");
                goto checkpoint_1; // returns to main content selection menu of football
            }
            else if (player == 0)
            {
                system("cls");
                exit(0); //EXITS THE PROGRAM
            }
            else
            {
                cout << "No such option available! Please try again!" << endl;
                system("pause");
                system("cls");
                goto checkpoint_1_1; // returns to stat menu of football
            }
            break;

        checkpoint_1_2:
        case 3:
            cout << "                                      >>>>>> Welcome to Football <<<<<<" << endl
                 << endl;
            cout << "                                      X---------- View Stats ---------X" << endl
                 << endl;
            cout << "                                      1. View Top Players" << endl
                 << "                                      2. View Stats by Positions " << endl
                 << "                                      3. Return to Main Menu" << endl
                 << "                                      0. Exit the program" << endl
                 << endl;
            cout << "                                      Enter your choice: ";

            int stat;
            cin >> stat;
            system("cls");
            if (stat == 1)
            {
            checkpoint_1_2_1:
                int top;
                cout << "                                      >>>>>> Welcome to Football <<<<<<" << endl
                     << endl;
                cout << "                                      X----- View League Leaders -----X" << endl
                     << endl;
                cout << "                                      1. Top Goal Scorers" << endl
                     << "                                      2. Top Assists" << endl
                     << "                                      3. Cleansheets" << endl
                     << "                                      4. Top Defenders " << endl
                     << "                                      5. Least Goals Conceeded" << endl
                     << "                                      6. Return to Main Menu" << endl
                     << "                                      0. Exit the program" << endl
                     << endl;
                cout << "                                      Enter your choice: ";
                cin >> top;
                system("cls");

                switch (top)
                {
                case 1:
                    Display_top10_goal(A, Mf, D);
                    system("pause");
                    system("cls");
                    goto checkpoint_1_2_1;
                    break;
                case 2:
                    Display_top10_assist(A, Mf);
                    system("pause");
                    system("cls");
                    goto checkpoint_1_2_1;
                    break;
                case 3:
                    Display_top10_cleansheet(Gk);
                    system("pause");
                    system("cls");
                    goto checkpoint_1_2_1;
                    break;
                case 4:
                    Display_top10_defenders(D);
                    system("pause");
                    system("cls");
                    goto checkpoint_1_2_1;
                    break;
                case 5:
                    Display_top10_leastgoal(Gk);
                    system("pause");
                    system("cls");
                    goto checkpoint_1_2_1;
                    break;
                case 6:
                    system("cls");
                    goto checkpoint_1_2;
                    break;
                case 0:
                    system("cls");
                    exit(0);
                default:
                    cout << "No such option available! Please try again!" << endl;
                    system("pause");
                    system("cls");
                    goto checkpoint_1_2_1;
                    break;
                }
                system("pause");
                system("cls");
                goto checkpoint_1_2; // returns to stat menu of football
            }
            else if (stat == 2)
            {
            checkpoint_1_2_2:
                cout << "                                      1. Forward" << endl
                     << "                                      2. Mid-Field" << endl
                     << "                                      3. Defence " << endl
                     << "                                      4. Goal-keeper" << endl
                     << "                                      5. Return to Main Menu" << endl
                     << endl;
                cout << "                                      Enter your choice: ";

                int position;
                cin >> position;
                system("cls");
                switch (position)
                {
                case 1:
                    A->Display_stats_f_a(A);
                    system("pause");
                    system("cls");
                    goto checkpoint_1_2_2;
                    break;
                case 2:
                    Mf->Display_stats_f_m(Mf);
                    system("pause");
                    system("cls");
                    goto checkpoint_1_2_2;
                    break;
                case 3:
                    D->Display_stats_f_d(D);
                    system("pause");
                    system("cls");
                    goto checkpoint_1_2_2;
                    break;
                case 4:
                    Gk->Display_stats_f_gk(Gk);
                    system("pause");
                    system("cls");
                    goto checkpoint_1_2_2;
                    break;
                case 5:
                    system("cls");
                    goto checkpoint_1_2;
                    break;
                default:
                    cout << "No such option available! Please try again!" << endl;
                    system("pause");
                    system("cls");
                    goto checkpoint_1_2_2;
                    break;
                }
            }
            else if (stat == 3)
            {
                system("cls");
                goto checkpoint_1; // returns to main content selection menu of football
            }
            else if (stat == 0)
            {
                system("cls");
                exit(0); //EXITS THE PROGRAM
            }
            else
            {
                cout << "No such option available! Please try again!" << endl;
                system("pause");
                system("cls");
                goto checkpoint_1_2; // returns to stat menu of football
            }
            break;

        case 4:
            F->Standings_display_f();
            system("pause");
            system("cls");
            goto checkpoint_1; // returns to main content selection menu of football

        case 5:
            system("cls");
            goto start; // returns to main menu of the Program

        case 0:
            system("cls");
            exit(0); //EXITS the program

        default:
            cout << "No such option available! Please Try Again" << endl;
            system("pause");
            system("cls");
            goto checkpoint_1; // returns to main content selection menu of football in case of invalid option
        }
    }

    else if (num == 2)
    {
    checkpoint_2: // Goto point for Main menu of basketball
        B->Display_content_b();
        int switch_b; //For selecting options for basketball
        cin >> switch_b;
        system("cls");

        switch (switch_b)
        {
        case 1:
            B->Team_display_b();
            system("pause");
            system("cls");
            goto checkpoint_2; // returns to main content selection menu of basketball

        checkpoint_2_1:
        case 2:
            cout << "                                      >>>> Welcome to Basketball <<<<" << endl
                 << endl;
            cout << "                                      X--------- View Players --------X" << endl
                 << endl;
            cout << "                                      1. Search Player " << endl
                 << "                                      2. View All Players " << endl
                 << "                                      3. Return to Main Menu" << endl
                 << "                                      0. Exit the program " << endl
                 << endl;
            cout << "                                      Enter your choice: ";
            int player;
            cin >> player;
            system("cls");
            if (player == 1)
            {
                B->Search_player_b(B);
                system("pause");
                system("cls");
                goto checkpoint_2_1; // returns to player menu of basketball
            }
            else if (player == 2)
            {
                B->Player_display_b(B);
                system("pause");
                system("cls");
                goto checkpoint_2_1; // returns to player menu of basketball
            }
            else if (player == 3)
            {
                system("cls");
                goto checkpoint_2; // returns to main content selection menu of basketball
            }
            else if (player == 0)
            {
                system("cls");
                exit(0); //EXITS THE PROGRAM
            }
            else
            {
                cout << "No such option available! Please try again!" << endl;
                system("pause");
                system("cls");
                goto checkpoint_2_1; // returns to stat menu of basketball
            }
            break;

        checkpoint_2_2:
        case 3:
            cout << "                                      >>>> Welcome to Basketball <<<<" << endl
                 << endl;
            cout << "                                      X---------- View Stats ---------X" << endl
                 << endl;
            cout << "                                      1. League Leaders" << endl
                 << "                                      2. All Stats" << endl
                 << "                                      3. Return to Main Menu" << endl
                 << "                                      0. Exit the program" << endl
                 << endl;
            cout << "                                      Enter your choice: ";
            int stat;
            cin >> stat;
            system("cls");
            if (stat == 1)
            {
                system("cls");
            checkpoint_2_2_1:
                int top;
                cout << "                                      >>>> Welcome to Basketball <<<<" << endl
                     << endl;
                cout << "                                      X----- View League Leaders -----X" << endl
                     << endl;
                cout << "                                      1. Total Points" << endl
                     << "                                      2. Total Assists" << endl
                     << "                                      3. Total Rebounds" << endl
                     << "                                      4. Field Goal Percentage " << endl
                     << "                                      5. Three-point Percentage" << endl
                     << "                                      6. Free Throw Percentage" << endl
                     << "                                      7. Return to Main Menu" << endl
                     << "                                      0. Exit the program" << endl
                     << endl;
                cout << "                                      Enter your choice: ";
                cin >> top;
                system("cls");

                switch (top)
                {
                case 1:
                    B->Display_top10_b_p(B);
                    system("pause");
                    system("cls");
                    goto checkpoint_2_2_1;
                    break;
                case 2:
                    B->Display_top10_b_a(B);
                    system("pause");
                    system("cls");
                    goto checkpoint_2_2_1;
                    break;
                case 3:
                    B->Display_top10_b_r(B);
                    system("pause");
                    system("cls");
                    goto checkpoint_2_2_1;
                    break;
                case 4:
                    B->Display_top10_b_fg(B);
                    system("pause");
                    system("cls");
                    goto checkpoint_2_2_1;
                    break;
                case 5:
                    B->Display_top10_b_3p(B);
                    system("pause");
                    system("cls");
                    goto checkpoint_2_2_1;
                    break;
                case 6:
                    B->Display_top10_b_ft(B);
                    system("pause");
                    system("cls");
                    goto checkpoint_2_2_1;
                    break;
                case 7:
                    system("cls");
                    goto checkpoint_2_2;
                    break;
                case 0:
                    system("cls");
                    exit(0);
                default:
                    cout << "No such option available! Please try again!" << endl;
                    system("pause");
                    system("cls");
                    goto checkpoint_2_2_1;
                    break;
                }
                goto checkpoint_2_2; // returns to stat menu of basketball
            }
            else if (stat == 2)
            {
                B->Stats_display_b(B);
                system("pause");
                system("cls");
                goto checkpoint_2_2; // returns to stat menu of basketball
            }
            else if (stat == 3)
            {
                system("cls");
                goto checkpoint_2; // returns to main content selection menu of basketball
            }
            else if (stat == 0)
            {
                system("cls");
                exit(0); //EXITS THE PROGRAM
            }
            else
            {
                cout << "No such option available! Please try again!" << endl;
                system("pause");
                system("cls");
                goto checkpoint_2_2; // returns to stat menu of basketball
            }
            break;

        case 4:
            B->Standings_display_b();
            system("pause");
            system("cls");
            goto checkpoint_2; // returns to main content selection menu of basketball

        case 5:
            system("cls");
            goto start; // returns to main menu of the Program

        case 0:
            system("cls");
            exit(0); // EXITS Program

        default:
            cout << "No such option available! Please Try Again" << endl;
            system("pause");
            system("cls");
            goto checkpoint_2; // returns to main content selection menu of basketball in case of invalid option
        }
    }

    else if (num == 3)
    {
    checkpoint_3: // Goto point for Main menu of cricket
        C->Display_content_c();
        int switch_c; //For selecting options for cricket
        cin >> switch_c;
        system("cls");

        switch (switch_c)
        {
        case 1:
            C->Team_display_c();
            system("pause");
            system("cls");
            goto checkpoint_3; // returns to main content selection menu of cricket

        checkpoint_3_1:
        case 2:
            cout << "                                      >>>>>> Welcome to Cricket <<<<<<" << endl
                 << endl;
            cout << "                                      X--------- View Players --------X" << endl
                 << endl;
            cout << "                                      1. Search Player " << endl
                 << "                                      2. View All Players " << endl
                 << "                                      3. Return to Main Menu" << endl
                 << "                                      0. Exit the program " << endl
                 << endl;
            cout << "                                      Enter your choice: ";
            int player;
            cin >> player;
            system("cls");
            if (player == 1)
            {
            checkpoint_3_1_1:

                cout << "                                  1. Batsman" << endl
                     << "                                  2. Bowler" << endl
                     << "                                  3. All-Rounder " << endl
                     << "                                  4. Wicket-Keeper" << endl
                     << "                                  5. Return to Main Menu" << endl
                     << endl;
                cout << "                                  Enter your choice: ";

                int category;
                cin >> category;
                system("cls");
                cout << "Enter name of the player to search : ";
                string name;

                switch (category)
                {
                case 1:
                    cin >> name;
                    Bt->Search_player_c_bt(Bt, name);
                    system("pause");
                    system("cls");
                    goto checkpoint_3_1_1;
                    break;
                case 2:
                    cin >> name;
                    Bo->Search_player_c_bo(Bo, name);
                    system("pause");
                    system("cls");
                    goto checkpoint_3_1_1;
                    break;
                case 3:
                    cin >> name;
                    Ar->Search_player_c_ar(Ar, name);
                    system("pause");
                    system("cls");
                    goto checkpoint_3_1_1;
                    break;
                case 4:
                    cin >> name;
                    Wk->Search_player_c_wk(Wk, name);
                    system("pause");
                    system("cls");
                    goto checkpoint_3_1_1;
                    break;
                case 5:
                    system("cls");
                    goto checkpoint_3_1;
                    break;
                default:
                    cout << "No such option available! Please try again!" << endl;
                    system("pause");
                    system("cls");
                    goto checkpoint_3_1_1;
                    break;
                }
                system("pause");
                system("cls");
                goto checkpoint_3_1; // returns to player menu of cricket
            }
            else if (player == 2)
            {
                Bt->Player_display_c_bt(Bt);
                Bo->Player_display_c_bo(Bo);
                Ar->Player_display_c_ar(Ar);
                Wk->Player_display_c_wk(Wk);
                system("pause");
                system("cls");
                goto checkpoint_3_1; // returns to player menu of cricket
            }
            else if (player == 3)
            {
                system("cls");
                goto checkpoint_3; // returns to main content selection menu of cricket
            }
            else if (player == 0)
            {
                system("cls");
                exit(0); //EXITS THE PROGRAM
            }
            else
            {
                cout << "No such option available! Please try again!" << endl;
                system("pause");
                system("cls");
                goto checkpoint_3_1; // returns to stat menu of cricket
            }
            break;

        checkpoint_3_2:
        case 3:
            cout << "                                      >>>>>> Welcome to Cricket <<<<<<" << endl
                 << endl;
            cout << "                                      X---------- View Stats ---------X" << endl
                 << endl;
            cout << "                                      1. View League Leaders" << endl
                 << "                                      2. View Stats by Category " << endl
                 << "                                      3. Return to Main Menu" << endl
                 << "                                      0. Exit the program" << endl
                 << endl;
            cout << "                                      Enter your choice: ";

            int stat;
            cin >> stat;
            system("cls");
            if (stat == 1)
            {
            checkpoint_3_2_1:
                cout << "                                      >>>>>> Welcome to Cricket <<<<<<" << endl
                     << endl;
                cout << "                                      X----- View League Leaders -----X" << endl
                     << endl;
                cout << "                                      1. Top Run Scorers" << endl
                     << "                                      2. Highest Batting Strike Rates" << endl
                     << "                                      3. Highest Batting Average" << endl
                     << "                                      4. Top Wicket Takers" << endl
                     << "                                      5. Best Bowling Average" << endl
                     << "                                      6. Best Economy Rate" << endl
                     << "                                      7. Return to Previous Menu " << endl
                     << "                                      0. Exit" << endl
                     << endl;
                cout << "                                      Enter your choice: ";

                int field;
                cin >> field;
                system("cls");
                switch (field)
                {
                case 1:
                    Display_top10_run(Bt, Bo, Ar, Wk);
                    system("pause");
                    system("cls");
                    goto checkpoint_3_2_1;
                    break;
                case 2:
                    Display_top10_strikerate(Bt, Ar, Wk);
                    system("pause");
                    system("cls");
                    goto checkpoint_3_2_1;
                    break;
                case 3:
                    Display_top10_batavg(Bt, Ar, Wk);
                    system("pause");
                    system("cls");
                    goto checkpoint_3_2_1;
                    break;
                case 4:
                    Display_top10_wkt(Bo, Ar);
                    system("pause");
                    system("cls");
                    goto checkpoint_3_2_1;
                    break;
                case 5:
                    Display_top10_bowlavg(Bo, Ar);
                    system("pause");
                    system("cls");
                    goto checkpoint_3_2_1;
                    break;
                case 6:
                    Display_top10_eco(Bo, Ar);
                    system("pause");
                    system("cls");
                    goto checkpoint_3_2_1;
                    break;
                case 7:
                    system("cls");
                    goto checkpoint_3_2;
                    break;
                case 0:
                    system("cls");
                    exit(0);
                default:
                    cout << "No such option available! Please try again!" << endl;
                    system("pause");
                    system("cls");
                    goto checkpoint_3_2;
                    break;
                }
                system("pause");
                system("cls");
                goto checkpoint_3_2; // returns to stat menu of cricket
            }
            else if (stat == 2)
            {
            checkpoint_3_2_2:
                cout << "1. Batsman" << endl
                     << "2. Bowler" << endl
                     << "3. All-Rounder " << endl
                     << "4. Wicket-Keeper" << endl
                     << "5. Return to Main Menu" << endl;
                cout << "Enter your choice: ";

                int category;
                cin >> category;
                system("cls");
                switch (category)
                {
                case 1:
                    Bt->Display_stats_c_bt(Bt);
                    system("pause");
                    system("cls");
                    goto checkpoint_3_2_2;
                    break;
                case 2:
                    Bo->Display_stats_c_bo(Bo);
                    system("pause");
                    system("cls");
                    goto checkpoint_3_2_2;
                    break;
                case 3:
                    Ar->Display_stats_c_ar(Ar);
                    system("pause");
                    system("cls");
                    goto checkpoint_3_2_2;
                    break;
                case 4:
                    Wk->Display_stats_c_wk(Wk);
                    system("pause");
                    system("cls");
                    goto checkpoint_3_2_2;
                    break;
                case 5:
                    system("cls");
                    goto checkpoint_3_2;
                    break;
                default:
                    cout << "No such option available! Please try again!" << endl;
                    system("pause");
                    system("cls");
                    goto checkpoint_3_2_2;
                    break;
                }
            }
            else if (stat == 3)
            {
                system("cls");
                goto checkpoint_3; // returns to main content selection menu of cricket
            }
            else if (stat == 0)
            {
                system("cls");
                exit(0); //EXITS THE PROGRAM
            }
            else
            {
                cout << "No such option available! Please try again!" << endl;
                system("pause");
                system("cls");
                goto checkpoint_3_2; // returns to stat menu of cricket
            }
            break;

        case 4:
            C->Standings_display_c();
            system("pause");
            system("cls");
            goto checkpoint_3; // returns to main content selection menu of cricket

        case 5:
            system("cls");
            goto start; // returns to main menu of the Program

        case 0:
            system("cls");
            exit(0); // EXITS the program

        default:
            cout << "No such option available! Please Try Again" << endl;
            system("pause");
            system("cls");
            goto checkpoint_3; // returns to main content selection menu of cricket in case of invalid option
        }
    }
    else if (num == 0)
    {
        system("cls");
        exit(0); //EXITS the program
    }
    else
    {
        cout << "No such option available! Please Try Again" << endl;
        system("pause");
        system("cls");
        goto start; // returns to main content selection menu of cricket in case of invalid option
    }

    return 0;
}
