if [[ -z "$1" ]] || [[ -z "$2" ]]; then
    echo "Please provide the problem's number and name: ./moveSolution.sh 123 \"MY PROBLEM\""
    exit
fi

SOURCE_FILE_NAME="Source.cpp"
TEMPLATE_FILE="../template.cpp"

if [[ ! -e ./$SOURCE_FILE_NAME ]]; then
    echo "$SOURCE_FILE_NAME file is not present in current directory."
    exit
fi

FILE_NAME="$1_$2.cpp"
DESTINATION_PATH="../Solutions/$FILE_NAME"

if [[ -e $DESTINATION_PATH ]]; then
    while true; do
        echo "$FILE_NAME already exists in ../Solutions directory. Do you want to continue? (Y/n)"
        read check
        if [[ $check == "n" ]] || [[ $check == "Y" ]]; then
            break
        fi
    done
    if [[ $check == "n" ]]; then
        echo "Process cancelled."
        exit
    else
        echo "Overwriting file..."
    fi
fi


cp "./$SOURCE_FILE_NAME" "$DESTINATION_PATH.CRLF"
tr -d '\r' < "$DESTINATION_PATH.CRLF" > "$DESTINATION_PATH"
rm "$DESTINATION_PATH.CRLF"

echo "$DESTINATION_PATH has been created with LF line ending."

echo "Verifying that the files are identical..."
diff -s --strip-trailing-cr "./$SOURCE_FILE_NAME" "$DESTINATION_PATH"

while true; do
    echo "Replace ./$SOURCE_FILE_NAME with the template file, commit changes and push to GitHub? (Y/n)"
    read check
    if [[ $check == "n" ]] || [[ $check == "Y" ]]; then
        break
    fi
done
if [[ $check == "n" ]]; then
    echo "Exiting..."
    exit
else
    echo "Replacing $SOURCE_FILE_NAME with $TEMPLATE_FILE."
    cp "$TEMPLATE_FILE" "./$SOURCE_FILE_NAME"
    echo "Commiting changes with the message: 'problem $1'"
    git add "$DESTINATION_PATH"
    git commit -m "problem $1" 
    echo "Pushing to GitHub..."
    git push
fi
