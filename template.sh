#! /bin/zsh
OUTPUT_PATH=div2/757\ div2/
mkdir ${OUTPUT_PATH}

echo 1 > ${OUTPUT_PATH}in
echo 1 > ${OUTPUT_PATH}out
find . -name 'template.cpp' | xargs cat > ${OUTPUT_PATH}a.cpp
find . -name 'template.cpp' | xargs cat > ${OUTPUT_PATH}b.cpp
find . -name 'template.cpp' | xargs cat > ${OUTPUT_PATH}c.cpp
find . -name 'template.cpp' | xargs cat > ${OUTPUT_PATH}d.cpp
find . -name 'template.cpp' | xargs cat > ${OUTPUT_PATH}e.cpp

