
#include <SPI.h>  //Importamos librería comunicación SPI
#include <Dhcp.h>
#include <Dns.h>
#include <Ethernet2.h>
#include <EthernetClient.h>
#include <EthernetServer.h>
#include <EthernetUdp2.h>
#include <Twitter.h>
#include <util.h>


byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 1, 70); //Le damos la IP elegida a Arduino
EthernetServer server(80); //Creamos un servidor Web con el puerto 80 que es el puerto HTTP por defecto

int led = 6; //Pin del led
String estado = "OFF"; //Estado del Led inicialmente "OFF"

void setup()
{
  Serial.begin(9600);

  // Inicializamos la comunicación Ethernet y el servidor
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());

  pinMode(led, OUTPUT);
}

void loop()
{
  EthernetClient client = server.available(); //Creamos un cliente Web

  if (client) {// Entra en el "if" si detecta un cliente a través de una petición HTTP
    Serial.println("new client");
    boolean currentLineIsBlank = true; //Una petición HTTP acaba con una línea en blanco
    String cadena = ""; //Creamos una cadena de caracteres vacía
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();//Leemos la petición HTTP carácter por carácter
        Serial.write(c);//Visualizamos la petición HTTP por el Monitor Serial
        cadena.concat(c);//Unimos el String 'cadena' con la petición HTTP (c). De esta manera convertimos la petición HTTP a un String

        //Ya que hemos convertido la petición HTTP a una cadena de caracteres, ahora podremos buscar partes del texto.
        int posicion = cadena.indexOf("LED="); //Guardamos la posición de la instancia "LED=" a la variable 'posicion'

        if (cadena.substring(posicion) == "LED=ON") //Si a la posición 'posicion' hay "LED=ON"
        {
          digitalWrite(led, HIGH);
          estado = "ON";
        }
        if (cadena.substring(posicion) == "LED=OFF") //Si a la posición 'posicion' hay "LED=OFF"
        {
          digitalWrite(led, LOW);
          estado = "OFF";
        }

        //Cuando reciba una línea en blanco, quiere decir que la petición HTTP ha acabado y el servidor Web está listo para enviar una respuesta
        if (c == '\n' && currentLineIsBlank) {

          // Enviamos al cliente una respuesta HTTP
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println();

          //Página web en formato HTML
          client.println("<html>");
          client.println("<head>");
          client.println("</head>");
          client.println("<body>");
          client.println("<h1 align='center'>Arduino Ethernet Shield</h1><h3 align='center'>Equipo 3</h3><h5 align='center'>LED controlado por servidor WEB</h5>");
          //Creamos los botones. Para enviar parametres a través de HTML se utiliza el metodo URL encode. Los parámetros se envian a través del símbolo '?'
          client.println("<div style='text-align:center;'>");
          client.println("<button onClick=location.href='./?LED=ON\' style='margin:auto;background-color: #FF0000;color: snow;padding: 10px;border: 1px solid #3F7CFF;width:65px;'>");
          client.println("ON");
          client.println("</button>");
          client.println("<button onClick=location.href='./?LED=OFF\' style='margin:auto;background-color: #FF0000;color: snow;padding: 10px;border: 1px solid #3F7CFF;width:65px;'>");
          client.println("OFF");
          client.println("</button>");
          client.println("<br /><br />");
          client.println("<b>LED = ");
          client.print(estado);
          client.println("</b><br />");
          client.println("</b></body>");
          client.println("</html>");
          break;
        }
        if (c == '\n') {
          currentLineIsBlank = true;
        }
        else if (c != '\r') {
          currentLineIsBlank = false;
        }
      }
    }
    //Dar tiempo al navegador para recibir los datos
    delay(1);
    client.stop();// Cierra la conexión
  }
}
