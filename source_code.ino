int outa=7;
int outb=8;
int outc=5;
int outd=4;
int vitr=3;
int vitl=9;

//ultrason const
const int trigpin=1;
const int echopin=2;
long duration;
int distance;

void setup()  {
    pinMode(outa,OUTPUT);
    pinMode(outb,OUTPUT);
    pinMode(vitl,OUTPUT);
    pinMode(outd,OUTPUT);
    pinMode(outc,OUTPUT);
    pinMode(vitr,OUTPUT);
    
    //ultrason
    pinMode(trigpin,OUTPUT);
    pinMode(echopin,INPUT);
    
    //ledpins
    pinMode(10,OUTPUT);
    pinMode(11,OUTPUT);
    pinMode(12,OUTPUT);
    pinMode(13,OUTPUT);
}
void loop() {
    if(ultrason() <= 60) {
        forward();
        ledbleue();
        if(detectligne()) {
            ledrouge();
            backward();
            turn1();
            search();
        }
    } else {
        if( detectligne() ) {
            ledrouge();
            backward();
            turn1();
            search();
        } else {
            search();
        }
    }

//fin loop
}

void search() {
    ledvert();
    turn();
}

boolean detectligne() {
    int sensorValue = analogRead(A0);
    delay(1);
    if (sensorValue==0)
        return true;
    else
        return false;
}

void forward() {
    digitalWrite(outa,HIGH);
    digitalWrite(outb,LOW);
    analogWrite(vitl,255);

    digitalWrite(outd,HIGH);
    digitalWrite(outc,LOW);
    analogWrite(vitr,255);
}

void stopp() {
    digitalWrite(outa,LOW);
    digitalWrite(outb,LOW);

    digitalWrite(outc,LOW);
    digitalWrite(outd,LOW);
    delay(1000000);
}

void turn() {
    digitalWrite(outa,HIGH);
    digitalWrite(outb,LOW);
    analogWrite(vitl,100);

    digitalWrite(outc,HIGH);
    digitalWrite(outd,LOW);
    analogWrite(vitr,100);
//delay(1000);
}

void turn1() {
    digitalWrite(outa,HIGH);
    digitalWrite(outb,LOW);
    analogWrite(vitl,255);

    digitalWrite(outc,HIGH);
    digitalWrite(outd,LOW);
    analogWrite(vitr,255);
    delay(500);
}

void backward() {
    digitalWrite(outb,HIGH);
    digitalWrite(outa,LOW);
    analogWrite(vitl,255);

    digitalWrite(outc,HIGH);
    digitalWrite(outd,LOW);
    analogWrite(vitr,255);
    delay(1000);
}

int ultrason() {
    digitalWrite(trigpin,LOW);
    delay(2);

    digitalWrite(trigpin,HIGH);
    delay(10);
    digitalWrite(trigpin,LOW);

    duration=pulseIn(echopin,HIGH);
    distance=duration*0.034/2;

    return distance;

}

void ledrouge() {
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(13,LOW);
    digitalWrite(10,HIGH);
    delay(500);
}
void ledbleue() {
    digitalWrite(12,HIGH);
    digitalWrite(13,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(13,HIGH);
    delay(500);
}

void ledvert() {
    digitalWrite(12,HIGH);
    digitalWrite(13,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
    delay(500);
}
