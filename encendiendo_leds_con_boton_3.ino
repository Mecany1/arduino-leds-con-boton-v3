int button_pressed = 0;
int active_leds = 0;

void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT); 
}

void loop() {
  int button_status = digitalRead(2);
  if(button_status==HIGH) {
    button_pressed = 1;
  } else if(button_status==LOW && button_pressed==1) {
    button_pressed = 0;
    active_leds++;
  }

  

  if(active_leds>3) {
    active_leds = 0;
  }

  switch(active_leds) {
    case 1:
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
    break;
    case 2:
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
    break;
    case 3:
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
    break;
    default:
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
    break;
  }
  
  delay(100);
}
