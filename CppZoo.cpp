#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string genUniqueID(string species, int numOfSpecies) {
    
    string uniqueID;
    
    if (species == "hyena") {
        uniqueID = "hy0" + to_string(numOfSpecies);
    }
    else if (species == "lion") {
        uniqueID = "li0" + to_string(numOfSpecies);
    }
    else if (species == "tiger") {
        uniqueID = "ti0" + to_string(numOfSpecies);
    }
    else if (species == "bear") {
        uniqueID = "be0" + to_string(numOfSpecies);
    }
    else {
        uniqueID = "error";
    }

    return uniqueID;
}



string calcBirthdate(int years, string season) {
    int birthYear = 0;
    string birthDate;
    birthYear = 2023 - years;
    string monthDay;
    if (season == "spri") {
        monthDay = "Mar 21";
    }
    else if (season == "summ") {
        monthDay = "Jun 21";
    }
    else if (season == "fall") {
        monthDay = "Sep 21";
    }
    else if (season == "wint") {
        monthDay = "Dec 21";
    }
    else {
        monthDay = "Jan 1";
    }
    birthDate = monthDay + ", " + to_string(birthYear);
    return birthDate;
}


int main()
{
    cout << "The Zoo Program!\n";
    string myTextStr;

    string lines[4];

    int lineNum = 0;
    int position = 0;
    int startPos = 0;
    int endPos = 0;
    int numOfHyenas = 0;
    int numOfLions = 0;
    int numOfTigers = 0;
    int numOfBears = 0;
    string birthSeason = "";
    string birthDay = "";
    string sex = "";
    string uniqueID = "";
    string species = "";
    string color = "";
    string outputLine = "";

    lineNum = 0;
    try {
        
        ifstream myFile("C:/cStuff/arrivingAnimals.txt");
        
       
        cout << "\n\n Contents of C:/cStuff/arrivingAnimals.txt ...";
        while (getline(myFile, myTextStr)) {
            
            cout << "\n" << myTextStr;
            
            lines[lineNum] = myTextStr;
            lineNum++;
        }
        cout << "\n  End of C:/cStuff/arrivingAnimals.txt ...\n\n";
        
        myFile.close();
    }
    catch (...) {
        cout << "\nException caught! \n";
    }

    string oneLine = lines[3];

    cout << "\n\n" << oneLine << "\n\n";
  
    int numYears = 0;
    string sex;
    string species;
    string uniqueID;
    string birthSeason;
    string color;
    int weight = 0;
    string origin;

    numYears = stoi(oneLine.substr(0, 2));
    cout << "\n numYears = " << numYears;

    position = oneLine.find("born in");
    cout << "\n position = " << position;
    birthSeason = oneLine.substr(position + 8, 4);
    cout << "\n birthSeason = " << birthSeason;

    cout << "\n Birth Date is... " << calcBirthdate(numYears, birthSeason);


    position = oneLine.find(" ");
    position = oneLine.find(" ", position+1);
    position = oneLine.find(" ", position+1);
    startPos = position + 1;
   
    endPos = oneLine.find(" ", startPos);
    sex = oneLine.substr(startPos, endPos - startPos);
    cout << "\n sex is..." << sex;


    startPos = endPos + 1;
    endPos = oneLine.find("," , startPos);
    species = oneLine.substr(startPos, endPos - startPos);
    cout << "\n species is..." << species;

  
    if (species == "hyena") {
        numOfHyenas++;
        uniqueID = genUniqueID("hyena", numOfHyenas);
    }
    else if (species == "lion") {
        numOfLions++;
        uniqueID = genUniqueID("lion", numOfLions);
    }
    else if (species == "tiger") {
        numOfTigers++;
        uniqueID = genUniqueID("tiger", numOfTigers);
    }
    else if (species == "bear") {
        numOfBears++;
        uniqueID = genUniqueID("bear", numOfBears);
    }
    else {
      
    }

    cout << "\n uniqueID is..." << uniqueID;


}