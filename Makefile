headerFiles = LevelManager.h Bob.h Thomas.h PlayableCharacter.h Engine.h TextureHolder.h
sourceFiles = LoadLevel.cpp LevelManager.cpp Bob.cpp Thomas.cpp PlayableCharacter.cpp Engine.cpp Draw.cpp Input.cpp Update.cpp TextureHolder.cpp main.cpp
	
Thomas-run: $(headerFiles) $(sourceFiles)
	g++ -o Thomas-run $(sourceFiles) -lsfml-graphics -lsfml-window -lsfml-system
