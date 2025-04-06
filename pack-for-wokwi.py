# python3
# Uploading/updating multiple files to Wokwi is a pain, so this script combines all the files into a single file
# so that you can easily copy and paste it into Wokwi's editor.

# ORDER matters! This is manually set
files_to_combine = [
    # IO FILES
    "src/io_config.hpp",    # no dependencies
    # AUDIO FILES
    "src/audio/Note.hpp",
    "src/audio/Song.hpp",   # must come after Note.hpp as it uses it
    "src/audio/SongPlayer.hpp", # must come after Song.hpp as it uses it
    "src/audio/songs.hpp",  # must come after Song.hpp as it uses it
    "src/audio/songs.cpp",  # must come after songs.hpp as it uses it
    # MAIN FILE
    "embedded-ff7-fanfare.ino",  # should come after all other files
]

# foreach loop to read each file and append its content to a single string
combined_code = ""
for file in files_to_combine:
    with open(file, "r") as f:
        # add a comment with the file name
        separator = "//" + "/" * 80 + "\n"
        combined_code += separator
        combined_code += f"// FILE: {file}\n"
        combined_code += separator

        # read the file content and append it to the combined code
        combined_code += f.read()
        combined_code += "\n\n"

# remove pragmas and includes
combined_code = combined_code.replace("#pragma once", "// #pragma once")

# remove any includes that use quotes with a regex
combined_code = combined_code.replace('#include "', '// #include "')

# combined_code = re.sub(r'#include\s*"(.*?)"', "", combined_code)

# write the combined code to a new file
with open("combined_code.txt", "w") as f:
    f.write(combined_code)

print("Combined code written to combined_code.txt")
