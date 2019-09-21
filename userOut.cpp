#include "userOut.h"

void UserOutput::dataload(bool success) {
  if(success) {
    cout << "Data import success." << endl;
    cout << endl;
  } else {
    cout << "Data load failure!" << endl;
    cout << "\"If you're seeing this, the code is in what I thought was an unreachable state. I could give you advice for what to do. But honestly, why should you trust me? I clearly screwed this up. I'm writing a message that should never appear, yet I know it will probably appear someday. On a deep level, I know I'm not up to this task. I'm so sorry.\"" << endl;
    cout << "\t -Randall Munroe" << endl;
  }
}

void UserOutput::charLookup() {
  cout << "All assets are loaded and ready." << endl;
  cout << "                                     `$/              " << endl;
  cout << "           __                        O$               " << endl;
  cout << "       _.-\"  )                        $'              " << endl;
  cout << "    .-\"`. .-\":        o      ___     ($o              " << endl;
  cout << " .-\".-  .'   ;      ,st+.  .' , \\    ($               " << endl;
  cout << ":_..-+\"\"    :       T   \"^T==^;\\;;-._ $\\              " << endl;
  cout << "   \"\"\"\"-,   ;       '    /  `-:-// / )$/              " << endl;
  cout << "        :   ;           /   /  :/ / /dP               " << endl;
  cout << "        :   :          /   :    )^-:_.l               " << endl;
  cout << "        ;    ;        /    ;    `.___, \\           .-," << endl;
  cout << "       :     :       :  /  ;.-\"\"\"   \\   \\\"\"\"-,    /  ;" << endl;
  cout << "       ;   :  ;      ; :   :         \\   \\    \\ .'  / " << endl;
  cout << "       ;   ;  :      ;   _.:          ;   \\  .-\"   /l " << endl;
  cout << "       ;.__L_.:   .-\";  :  ;          :_   \\/ .-\" / ; " << endl;
  cout << "       :      ;.-\"   :  ; :        _  : \\  / /  .' /  " << endl;
  cout << "        ;            ;  ;  ;   _.-\" \"-.\\ :/   .'  :   " << endl;
  cout << "        :            ;  ;  :.-j-,      `;:_.+'    ;   " << endl;
  cout << "        ;           _;  :  :.'  ;      / : /     :    " << endl;
  cout << "        '-._..__.--\"/   :  :   /      /  ;/      ;    " << endl;
  cout << "                   :    ;  ;  /      ,  //      :     " << endl;
  cout << "                   ;    ; / .'( ,    ; ::\\     .:     " << endl;
  cout << "                   :    :  / .-dP-'  ;-'; `---' :     " << endl;
  cout << "                    `.   \"\" ' s\")  .'  /        '     " << endl;
  cout << "                      \\           /;  :       .'      " << endl;
  cout << "                    _  \"-, ;       '.  \\    .'        " << endl;
  cout << "                   / \"-.'  :    .--.___.`--'          " << endl;
  cout << "                  /      . :  .'                      " << endl;
  cout << "                  )_..._  \\  :  bug                   " << endl;
  cout << "                 : \\    '. ; ;                        " << endl;
  cout << "                 ;  \\    ;   :                        " << endl;
  cout << "                 :   \\  /    ;                        " << endl;
  cout << "                  \\   )/    /                         " << endl;
  cout << "                   `-.___.-'                           " << endl;
  cout << "\n";
  select();
}

void UserOutput::select() {
  cout << "Select one: " << endl;
  cout << "\t" << "1. I know the character's name. (Search by Name)" << endl;
  cout << "\t" << "2. I know what year the character first appeared in the Marvel comic universe. (Search by Year)" << endl;
  cout << "\t" << "0. Get me out of here! (Exit)" << endl;
}

void UserOutput::askname() {
  cout << "Enter name search query: ";
}

void UserOutput::year() {
  cout << "Enter year search query: ";
}

void UserOutput::invalid(string invalidString) {
  cout << "Invalid: " << invalidString << endl;
}

void UserOutput::invalid(double invalidNumber) {
  cout << "Invalid: " << invalidNumber << endl;
}

void UserOutput::formatName(vector<string> matchList) {
  cout << "\n";
  cout << "Search Results:" << endl;
  for (int i =  0; i < matchList.size(); i++) {
    cout << "\n";
    cout << "\t" << i+1 << ". " << matchList.at(i);
  }
  confirmName();
}

void UserOutput::confirmName() {
  cout << "\n" << endl;
  cout << "Please select the nearest match from the list above" << endl;
}

void UserOutput::formatChar(vector<charChar> characterList) {
  cout << endl;
  cout << "Search Results: " << endl;
  cout << "\n";
  for(int i = 0; i < characterList.size() - 1; i++) {
    charChar character = characterList.at(i);
    cout << "\t" << i+1 << ". " << character.name << endl; 
  }
  charSelect();
}

void UserOutput::charSelect() {
  cout << endl;
  cout << "Select character to view." << endl;
  cout << "\n";
}

void UserOutput::showChar(charChar marvelCharacter) {
  cout << "\n" + marvelCharacter.name + ": " + marvelCharacter.identity + ", " + marvelCharacter.alignment + ", " + marvelCharacter.eyeColor + ", " + marvelCharacter.hairColor + ", " + marvelCharacter.sex + ", " + marvelCharacter.sexualOrientation + ", " + marvelCharacter.living + ", " + marvelCharacter.numOfAppearances+ " appearances. \nFirst appearance: " + marvelCharacter.firstAppearanceDate + ", " + marvelCharacter.firstAppearanceYear + "." << endl;
}