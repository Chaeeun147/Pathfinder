// --- PIN SETUP ---
int BUT1 = D0;
int BUT2 = D1;
int BUT3 = D2;

int LED1 = D3;
int LED2 = D4;
int LED3 = D5;
int LED4 = D6;

// --- VARIABLES ---
unsigned long but1time = 0;
unsigned long but2time = 0;
unsigned long but3time = 0;
unsigned long startTime = 0;

void setup() {
  // Set buttons as inputs with pull-up resistors (LOW = pressed)
  pinMode(BUT1, INPUT_PULLUP);
  pinMode(BUT2, INPUT_PULLUP);
  pinMode(BUT3, INPUT_PULLUP);
  
  // Set LEDs as outputs
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  startTime = millis();
}

void loop() {
  
  // ==========================================
  // STEP 1: RECORD THE TIMES ONLY
  // No lights in this section! Just recording when a button is pressed.
  // ==========================================
  
  if (digitalRead(BUT1) == LOW) {
    but1time = millis();
  }
  
  if (digitalRead(BUT2) == LOW) {
    but2time = millis();
  }
  
  if (digitalRead(BUT3) == LOW) {
    but3time = millis();
  }


  // ==========================================
  // STEP 2: CONTROL THE LIGHTS ONLY
  // Every LED gets its own separate rules based on the times we saved above.
  // ==========================================

  // --- LED 1 ---
  if (digitalRead(BUT1) == LOW) {
    digitalWrite(LED1, HIGH);
  } else {
    digitalWrite(LED1, LOW);
  }

  // --- LED 2 ---
  if (digitalRead(BUT2) == LOW || abs((long)(but2time - but1time)) <= 2000) {
    digitalWrite(LED2, HIGH);
  } else {
    digitalWrite(LED2, LOW);
  }

  // --- LED 3 ---
  if (digitalRead(BUT3) == LOW || abs((long)(but3time - but1time)) <= 2000) {
    digitalWrite(LED3, HIGH);
  } else {
    digitalWrite(LED3, LOW);
  }

  // --- LED 4 ---
  if (digitalRead(BUT2) == LOW && digitalRead(BUT3) == LOW) {
    digitalWrite(LED4, HIGH);
  } else {
    digitalWrite(LED4, LOW);
  }

}