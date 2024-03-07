# EspanaKrypt Builder

Folders:
- dist/ contains the final EspanaKrypt.exe crypter program, and an example helloworld.exe program
- source/ contains the source of the EspanaKrypt (crypter) program, Galleon (stub) program
- utils/ contains any tools for the builder 


Compile source/Armada.cpp to create the original PE.
```
g++ ./source/Armada.cpp -static -o ./tmp/Armada.exe
```

Convert Armada.exe to bytes array C++ header file, for an input file to become a header file for our source.
```
./utils/BTCH.exe ./tmp/Armada.exe ./source/Galleon.h
```

Compile source/EspanaKrypt.cpp
```
g++ ./source/EspanaKrypt.cpp -static -o ./dist/EspanaKrypt.exe
```

## Optional

You can modify BTCH (Bytes to C++ Header) in utils/source/BTCH.cpp if you want a custom header file in the future.

You can modify helloworld.cpp in source directory for a new testing file. 
