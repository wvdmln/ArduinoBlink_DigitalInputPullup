# ArduinoBlink_DigitalInputPullup
 
Blink LED_BUILTIN + "Schakelaar" die "Lampje" stuurt

LED_BUILTIN gaat aan voor 5s, daarna uit voor 5 s, herhalend.
Schakelaar bedient INPUT 2 (wordt hier gebruikt met de ingebouwde pullup-weerstand)
Wanneer de schakelaar (INPUT 2) bediend wordt, willen we dat het lampje brandt (OUTPUT 12)

Het Lampje reageert met een vertraging op het bedienen van de schakelaar ==> HOE KAN DAT?
Het probleem is de delay-functie. Tijdens delay doet de Arduino niets en checkt bijgevolg dus ook de status van de input niet meer