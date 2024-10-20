




void System_init() {
  boiler_pump.Trigger(false);
  cooler_pump.Trigger(false);
  tank_pump.Trigger(false);
  
  boiler_solenide.Trigger(false);
  cooler_solenide.Trigger(false);
  tank_solenide.Trigger(false);
  Wout_solenide.Trigger(false);
  Mout_solenide.Trigger(false);
  
}
