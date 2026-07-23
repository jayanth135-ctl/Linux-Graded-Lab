# Question 1 - Explanation

## Command
mkdir submissions backup

Explanation:
This command creates two directories. The submissions folder stores student assignment files, and the backup folder stores copies of unique files.

## Command
chmod +x duplicate_backup.sh

Explanation:
This command gives execute permission to the shell script so that it can be run.

## Command
./duplicate_backup.sh

Explanation:
This command executes the shell script. It identifies duplicate files, backs up unique files, creates a report, and stores errors separately.

## Command
cat report.txt

Explanation:
Displays the generated report containing the number of processed, duplicate, and backed-up files.

## Command
cat errors.log

Explanation:
Displays error messages generated during execution. If empty, no errors occurred.

## Linux Concepts Used

- Shell Script: Automates tasks using Bash commands.
- Redirection (>, 2>>): Stores output and errors in separate files.
- cmp: Compares two files.
- cp: Copies unique files to the backup folder.
- basename: Extracts the filename from a file path.