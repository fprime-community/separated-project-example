@ Signal Generator Settings Changed
event SignalGen_SettingsChanged(
                                 Frequency: U32
                                 Amplitude: F32
                                 Phase: F32
                                 SignalType: Reference.SignalType
                               ) \
  severity activity low \
  id 0 \
  format "Set Frequency(Hz) {}, Amplitude {f}, Phase {f}, Signal Type {}"
