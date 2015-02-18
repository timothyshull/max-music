This app is designed to be a simple game or learning tool that can be used to increase a user’s awareness of the notes on a keyboard, increase speed with note dictation or simply promote coordination between two people to sound a melody.  

Directions:

1) The files “Networking_App_Performer_iOS.pd” and “NetworkingAppiPad.mmp” (or …iPhone.mmp) should be loaded into Mob Mu Plat on the iOS device(s) being used.  This/these will be the performer(s).

2) The files “Networking_App_Conductor_OSX.pd” and “PdWrapper.pd” should be opened on a computer.  This will be the conductor.  

3) The conductor should open the spigot to send network messages, set a metronome BPM (this corresponds to the difficulty level, lower for easier, higher for harder), and start the metronome. 

4)  When the conductor plays a note using the computer keyboard this note will appear on the performer’s screen.  The performer should play this note on their keyboard as quickly as possible.  If they play the correct note within the time span of one beat of the metronome the note will sound until the next beat of the metronome.  If they play the wrong note the sound will turn off or no note will sound.  

5) The file “Networking_App_Master.pd” can be used as a switchable patch to network between multiple computers in this same manner.  Note: this should not be used to network with iOS devices.    