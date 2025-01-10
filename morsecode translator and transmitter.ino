const int PushButton = 2;
const int LEDPIN1 = 4;
const int LEDPIN2 = 5;
const int LEDPIN3 = 6;
const int BUZZER1 = 8;
const int BUZZER2 = 9;
const int BUZZER3 = 10;
void setup() {
  pinMode(PushButton,INPUT_PULLUP);
  pinMode(LEDPIN1,OUTPUT);
  pinMode(LEDPIN2,OUTPUT);
  pinMode(LEDPIN3,OUTPUT);
  pinMode(BUZZER1,OUTPUT);
  pinMode(BUZZER2,OUTPUT);
  pinMode(BUZZER3,OUTPUT);
}

void loop() {
  int buttonread = digitalRead(PushButton);
  if(buttonread==1){
    String ConvertedString = TranslateMessage("godzilla is king of monster");
    Transmitmessage(ConvertedString);
    delay(5000);
  }

}
void Transmitmessage(String message) {
  for(int i=0;i<message.length();i++) { //scans through the
     char symbol = message.charAt(i);
     if (symbol == '.') {
            dot();
        } 
     else if (symbol == '-') {
        dash();
      }
     else if (symbol == '/'){
      backslash();
      }
        }
  }
void dot() {
    digitalWrite(LEDPIN1, HIGH);
    delay(100); // Dot duration: 200 milliseconds
    tone(BUZZER1,10000);
    delay(100);
    digitalWrite(LEDPIN1, LOW);
    noTone(BUZZER1);
}
void dash() {
    digitalWrite(LEDPIN2, HIGH);
    delay(100); // Dash duration: 600 milliseconds
    tone(BUZZER2,7500);
    delay(100);
    digitalWrite(LEDPIN2, LOW);
    noTone(BUZZER2);
}
void backslash(){
  digitalWrite(LEDPIN3 , HIGH);
  delay(100);
  tone(BUZZER3,5000);
  delay(100);
  noTone(BUZZER3);
  digitalWrite(LEDPIN3 , LOW);
}

 String TranslateMessage(String message){
  const String morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "/", ""};
  String morseText = "";
  for(int i=0;i<message.length();i++){
    char c = tolower(message[i]);
    if(isalpha(c)){ // if variable is alphabet
      morseText += morseCode[c-'a'];

    }
    else if(isdigit(c)){ //if variable is digit
      morseText += morseCode[c - '0' + 26];
    }
    else if(c==' '){
      morseText+= "/";
    }
    morseText += " ";
  }
  return morseText;
 }