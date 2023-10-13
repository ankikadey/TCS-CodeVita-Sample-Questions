/*The people of Kingdoms of Westeros are very organized. They are very devoted to their leader and cannot live without a leader even for a single day. Marriages, divorces, births, and deaths are everyday things in Westeros and because of these events people of Westeros need to spend their time on choosing the leader. People badly need a programme to find the new leader in case of these events. The criteria to choose the leader is as below.

The leader of the family will be the oldest person. [Age of each member in a particular family will be different]. For simplicity, consider surname as family name. In the input though family name will be mentioned explicitly.
2 or more families are said to be related if a boy from one family has married a girl in the other family. Thus, related families will have a single leader who will be the senior most person from the newly formed cluster of families. If 2 members from this cluster have the same age, then the person with larger family will be the leader of the new cluster. If that also results in a tie, then the person whose name comes first in lexicographical order will be the leader
After marriage the wife will assume husband's family name and will be counted as a family member of the husband's family.
If new Birth happens, children will take fathers family name.
If Divorce happens 2 families will split, the wife will assume her maiden family name. All children will be counted as members of their father's family. The families will choose new leaders.
After divorce the wife will assume her birth family name and hence husband's family may no longer be relatives, provided there is no other marriage bond between these two families.
If any Death happens and the deceased person was the leader, the family / cluster will choose a new leader. If a married women dies, the relation between 2 families will break i.e. they will split by family name
If a married woman dies the relation between 2 families (husband and wife) will break provided there is no other marriage bond between 2 families. From perspective of answering queries, unless the husband remarries, the name of the dead wife should be printed as Spouse Name
If a married man dies the relation between 2 families (husband and wife) will not break. Wife will still be considered as husband's family until she marries someone else. From perspective of answering queries, unless the wife remarries, the name of the dead husband should be printed as Spouse Name
Every Person in Westeros has a unique name.
Every person in a particular family will have different age.
Polygamy or polyandry is not permitted. A person can have only one spouse at any time. Although Remarriage after divorce is possible
NA will appear in input wherever not applicable
Constraints
1 <= N <= 500

1 <= E <= 100

Input
First line contains an integer denoting the number of records (N).

Next N lines contain one record each i.e., space separated data about every person in the format Firstname FamilyName BirthFamilyName Gender FatherName SpouseName Age

Next line contains an integer denoting the number of events (E).

Next E lines contain data about respective event.

The events are recognized by keywords and apply to one of more persons as explained below

Marriage between Person1 and Person2 will be depicted as:
MA Person1 Person2
Divorce between Person1 and Person2 will be depicted as:
DI Person1 Person2
Birth will be depicted by:
BI NameOfTheNewBorn Gender Father Mother
Death will be depicted by:
DE Person1
Year Passed will be depicted by:
YP <Number of Years>
Print All:
PA
Print One:
PO Person1
For more clarity, refer Examples section

Output
Output only for events PA (Print All) and PO (Print One). For PO print only the person details provided in the input. For PA print all persons who are alive, separated by new line and sorted in lexicographical order of the person's name. No need to print details of dead person. Data must be computed internally for each event even if print is not followed by that event.

Print as below respectively separated by space for each person.

Firstname
Family Name
Birth Family Name
Gender
Father Name
Spouse Name
Age
Leader Name
Time Limit (secs)
1

Examples
Input

9

Jamie Lannister Lannister Male Tywin NA 50

Cersei Lannister Lannister Female Tywin NA 45

Tywin Lannister Lannister Male NA NA 70

Robert Baratheon Baratheon Male NA NA 50

Stannis Baratheon Baratheon Male NA NA 48

Renly Baratheon Baratheon Male NA NA 40

Edward Stark Stark Male NA Catelyn 48

Rob Stark Stark Male NA NA 14

Catelyn Stark Tully Female NA Edward 42

9

PA

MA Cersei Robert

PO Cersei

DE Tywin

PO Jamie

BI Joffrey Male Robert Cersei

YP 5

DI Cersei Robert

PA

Output

Catelyn Stark Tully Female NA Edward 42 Edward

Cersei Lannister Lannister Female Tywin NA 45 Tywin

Edward Stark Stark Male NA Catelyn 48 Edward

Jamie Lannister Lannister Male Tywin NA 50 Tywin

Renly Baratheon Baratheon Male NA NA 40 Robert

Rob Stark Stark Male NA NA 14 Edward

Robert Baratheon Baratheon Male NA NA 50 Robert

Stannis Baratheon Baratheon Male NA NA 48 Robert

Tywin Lannister Lannister Male NA NA 70 Tywin

Cersei Baratheon Lannister Female Tywin Robert 45 Tywin

Jamie Lannister Lannister Male Tywin NA 50 Robert

Catelyn Stark Tully Female NA Edward 47 Edward

Cersei Lannister Lannister Female Tywin NA 50 Jamie

Edward Stark Stark Male NA Catelyn 53 Edward

Jamie Lannister Lannister Male Tywin NA 55 Jamie

Joffrey Baratheon Baratheon Male Robert NA 5 Robert

Renly Baratheon Baratheon Male NA NA 45 Robert

Rob Stark Stark Male NA NA 19 Edward

Robert Baratheon Baratheon Male NA NA 55 Robert

Stannis Baratheon Baratheon Male NA NA 53 Robert

Explanation-

In the Sample inputs data is provided for 3 families viz. Lannister, Baratheon and Stark, and there is no relationship among them.

So, at first leader of each family been selected from each family separately based on oldest members.

After event of marriage between Robert and Cersei, Baratheon and Lannister become relatives and Tywin has been chosen leader of both the families. When Cersei's details are printed she is already married and hence her family name is now Baratheon.

After death of Tywin, Robert has been chosen leader although age of Jamie and Robert was same. Robert was chosen the leader since Baratheon family has more members than Lannister family. This can be seen when we printed Jamie's details.

Five years after Joffrey's birth and post the divorce of Robert and Cersei, relations between Lannister and Baratheon family have broken and Jamie became leader of Lannister family as he was the oldest. Joffrey stays with father's family name. As Tywin is dead his details have been not printed.*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Person {
    string firstName;
    string familyName;
    string birthFamilyName;
    string gender;
    string fatherName;
    string spouseName;
    int age;
    Person(string firstName, string familyName, string birthFamilyName, string gender, string fatherName, string spouseName, int age) : firstName(firstName), familyName(familyName), birthFamilyName(birthFamilyName), gender(gender), fatherName(fatherName), spouseName(spouseName), age(age) {}
};

map<string, Person> people;

void printPerson(const Person &p, const string &leaderName) {
    cout << p.firstName << " " << p.familyName << " " << p.birthFamilyName << " " << p.gender << " " << p.fatherName << " " << p.spouseName << " " << p.age << " " << leaderName << endl;
}

bool comparePeople(const pair<string, Person> &a, const pair<string, Person> &b) {
    if (a.second.familyName == b.second.familyName) {
        if (a.second.age == b.second.age) {
            return a.first < b.first;
        }
        return a.second.age > b.second.age;
    }
    return a.second.familyName < b.second.familyName;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string firstName, familyName, birthFamilyName, gender, fatherName, spouseName;
        int age;
        cin >> firstName >> familyName >> birthFamilyName >> gender >> fatherName >> spouseName >> age;
        people[firstName] = Person(firstName, familyName, birthFamilyName, gender, fatherName, spouseName, age);
    }

    int E;
    cin >> E;
    for (int i = 0; i < E; i++) {
        string event;
        cin >> event;
        if (event == "PA") {
            vector<pair<string, Person>> alivePeople;
            for (auto &p : people) {
                if (p.second.spouseName != "NA") {
                    p.second.familyName = people[p.second.spouseName].familyName;
                }
                if (p.second.gender == "Female" && p.second.spouseName == "NA") {
                    p.second.spouseName = p.second.familyName;
                }
                if (p.second.fatherName == "NA") {
                    alivePeople.push_back(p);
                }
            }
            sort(alivePeople.begin(), alivePeople.end(), comparePeople);
            for (auto &p : alivePeople) {
                printPerson(p.second, p.second.familyName);
            }
        } else if (event == "PO") {
            string personName;
            cin >> personName;
            printPerson(people[personName], people[personName].familyName);
        } else if (event == "MA") {
            string p1, p2;
            cin >> p1 >> p2;
            people[p1].spouseName = p2;
            people[p2].spouseName = p1;
        } else if (event == "DI") {
            string p1, p2;
            cin >> p1 >> p2;
            people[p1].spouseName = "NA";
            people[p2].spouseName = "NA";
        } else if (event == "BI") {
            string name, gender, father, mother;
            cin >> name >> gender >> father >> mother;
            people[name] = Person(name, father, father, gender, father, mother, 0);
        } else if (event == "DE") {
            string p;
            cin >> p;
            people.erase(p);
        } else if (event == "YP") {
            int years;
            cin >> years;
            for (auto &p : people) {
                p.second.age += years;
            }
        }
    }

    return 0;
}
