//      Name: Brayden Birt
//      Date: 03/22/23
// File name: lab9.cc


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
using namespace std;
//prototypes
void loadData(int dailyLow[], ifstream &ins);
int lowestTemp(int dailyLow[]);
int highestTemp(int dailyLow[]);
int averageTemp(int dailyLow[]);

int main() {

    ifstream inStream;
    string inFile = "athens_low_temps.txt";

    inStream.open(inFile);//open file
    
    if (inStream.fail())//check if file fails to open
    {
        cout << "Error: file not found" << endl;
        exit(0);
    }

    int dailyLow[30];
    loadData(dailyLow, inStream);

    cout << "The lowest daily low temperature was " << lowestTemp(dailyLow) << endl;

    cout << "The highest daily low temperature was " << highestTemp(dailyLow) << endl;

    cout << "The average daily low temperature was " << averageTemp(dailyLow) << endl;

    inStream.close();//close file
    return 0;
}

void loadData(int dailyLow[], ifstream &inStream){//load txt file into array
    for (size_t i = 0; i < 30; i++){
        inStream >> dailyLow[i];
    }
}

int lowestTemp(int dailyLow[]){
    int minTemp = dailyLow[0];//set first value as lowest
    for (size_t i = 0; i < 30; i++){
        if (dailyLow[i] < minTemp){// if new value is lower set as lowTemp
            minTemp = dailyLow[i];
        }

    }
    return minTemp;
}

int highestTemp(int dailyLow[]){
    int highTemp = dailyLow[0]; //set first value as highest
    for (size_t i = 0; i < 30; i++){
        if (dailyLow[i] > highTemp){ // if new value is higher set as highTemp
            highTemp = dailyLow[i];
        }

    }
    return highTemp;
    
}

int averageTemp(int dailyLow[]){
    int avgTemp = 0;
    for (size_t i = 0; i <= 30; i++){
        avgTemp += dailyLow[i]; // sum of all temperatures
    }

    return avgTemp / 30;// returns average value
    
}