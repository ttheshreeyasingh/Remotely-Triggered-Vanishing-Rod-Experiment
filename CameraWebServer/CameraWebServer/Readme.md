## Esp32-cam

   1. Connect a Arduino UNO to the laptop.
   2. Select Board: ESP32 Wrover Module
   3. Select Uplaod Speed: 115200
   4. Select Flash Frequency: 40 MHz
   5. Select partition Scheme: Huge APP (3MB No OTA/1MB SPIFFS)
   6. Select the appropriate port.
   7. Connect the RESET pin and the GND pin of the Arduino UNO.
   8. Connect the 3.3V/5V and GND pin of the Arduino and to the 3.3V/5V pin and GND pin of the Esp32-cam board.
   9. Connect the RX and TX of Arduino to RXD and TXD of Esp32-cam board.
  10. Connect the GPI0 and GND of Esp32-cam board.
  11. Push the code using the Arduino.
  12. Disconnect the GPI0 and GND pin of Esp32-cam board.
  13. Open the serial monitor and press RESET button on the Esp-32 cam board.
  14. Wait for the web-server link to appear on the serial monitor.
  15. Use the link in a web browser connected to the local internet network.
  16. If you get the error "Brownout detector was triggered", make sure you the Esp32-cam is powered properly.
  17. Make sure your wifi network is set on 2.4 GHz.
