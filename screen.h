void titleScreen(){
  Serial.println("Benvolgut al Snake de l\'ousmane i al Snake d\'en Viviano Espero que gaudeixis del teu Snake, merit de Juffrrenfa, pero idea de\'n Vivano");
}
void gameScreen(){
  Serial.println("Tu no jugaras mai, jaja es broma xddd");
  Serial.println("playing: "+string(playing)+", x: "+ string(x)+", y: "+ string(y)+", mc: "+ string(mc)+", pts: "+ string(p)+", apples:");
  for(int i = 0; i < sizex*sizey; i++)
    Serial.print(i+':'+apples[i]+' ');
  Serial.println("tail");
  for(int i = 0; i < snakeTail.Count(); i++)
    Serial.print(i+':'+snakeTail[i]+' ');
}
