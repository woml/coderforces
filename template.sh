#! /bin/zsh
OUTPUT_PATH=div3/

find . -name 'template.cpp' | xargs cat > ${OUTPUT_PATH}a.cpp
find . -name 'template.cpp' | xargs cat > ${OUTPUT_PATH}b.cpp
find . -name 'template.cpp' | xargs cat > ${OUTPUT_PATH}c.cpp
find . -name 'template.cpp' | xargs cat > ${OUTPUT_PATH}d.cpp
find . -name 'template.cpp' | xargs cat > ${OUTPUT_PATH}e.cpp

