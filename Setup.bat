rd /S /Q build
md /S /Q build
cmake -B "build" -S %cd%
mkdir "build/sandbox/Debug"
python scripts/CopyFiles.py "third-party/libsdl2/lib/x64/dll" "build/sandbox/debug"
python scripts/CopyFiles.py "third-party/glew/lib/Release/x64/dll" "build/sandbox/debug"

