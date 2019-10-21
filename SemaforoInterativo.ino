const int l_vm = 10; //Vermelho Veiculo
const int l_am = 11; //Amarelo Veiculo
const int l_vr = 12; //Verde Veiculo
const int p_vm =  9; //Vemelho Pedestre
const int p_vr =  7; //Verde Pedestre
const int botao = 2; //Botao
int estado_botao = 0;


void setup() {                
  
  pinMode(l_vm, OUTPUT); // Led Vermelho Veiculos
  pinMode(l_am, OUTPUT); // Led Amarelo Veiculos
  pinMode(l_vr, OUTPUT); //Led Vermelho Veiculos
  pinMode(p_vm, OUTPUT); //Led Vermelho Pedestres
  pinMode(p_vr, OUTPUT); //Led Verde Pedestres
  pinMode(botao, INPUT); //Botao de acionamento para pedestre
  
}

void loop() {
        //Led Verde de Veiculos Liga e espera pelo acionamento do botao
  digitalWrite(l_vr, HIGH);
  digitalWrite(p_vm, HIGH);
  
          //inicia a sequencia para o pedestre
 estado_botao = digitalRead(botao);
 if (estado_botao == HIGH){
     digitalWrite(l_vr, LOW);
     digitalWrite(l_am, HIGH);
     delay(2000);
     digitalWrite(l_am, LOW);
     
     //Abre o farol para o pedestre
     digitalWrite(p_vr, HIGH);
     digitalWrite(l_vm, HIGH);
     digitalWrite(p_vm, LOW);
     delay(2000);
     digitalWrite(p_vr, LOW);
     
     //inicia aviso de segurança para pedestre
     digitalWrite(p_vm, HIGH);
     delay(500);
     digitalWrite(p_vm, LOW);
     delay(500);
     digitalWrite(p_vm, HIGH);
     delay(500);
     digitalWrite(p_vm, LOW);
     delay(500);
     digitalWrite(p_vm, HIGH);
     delay(500);
     digitalWrite(p_vm, LOW);
     delay(500);
     digitalWrite(l_vm, LOW);
       //termina a sequencia do pedestre
       
       //impede o inicio da sequencia de pedestre por 5seg e liga o LED verde para veiculos
     digitalWrite(p_vm, HIGH);
     digitalWrite(l_vr, HIGH);
     delay (5000);
 }
}

