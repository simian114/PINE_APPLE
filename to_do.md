Simple Command
- [x] Execute a simple command with an absolute path like /bin/ls or any other command without options
Arguments
- [x] Execute a simple command with an absolute path like /bin/ls or any other command with arguments but without quotes and double quotes
- [x] Repeat multiple times with different commands and arguments
echo
- [x] Execute the echo command with or without arguments or options
- [x] Repeat multiple times with different arguments
exit
- [x] Execute exit command with or without arguments
- [x] Repeat multiple times with different arguments
- [x] Don't forget to relaunch the minishell
Return value of a process
- [x] Execute a simple command with absolute path like /bin/ls or any other command with arguments but without quotes and double quotes then execute echo $?
- [x] Check the printed value. You can repeat the same in bash and compare it.
- [ ] Repeat multiple times with different commands and arguments, use some failing commands like '/bin/ls filethatdoesntexist'
Semicolons
- [x] Execute multiple simple commands with absolute path with arguments but separate them with semicolons
- [x] Repeat multiple times with different commands and don't forget to try with or without whitespaces around the semicolons
Signals
- Try ctrl-C in an empty prompt
- Try ctrl-\ in an empty prompt
- Try ctrl-D in an empty prompt
- Try ctrl-C in a prompt after you wrote some stuff
- Try ctrl-D in a prompt after you wrote some stuff
- Try ctrl-\ in a prompt after you wrote some stuff
- Try ctrl-C after running a blocking command like cat or grep without arguments
- Try ctrl-\ after running a blocking command like cat or grep without arguments
- Try ctrl-D after running a blocking command like cat or grep without arguments
- Repeat multiple times with different commands
Double Quotes
- [x] Execute a simple command with absolute path with arguments but this time double quotes (you should include whitespaces and semicolons in the quotes)
- [ ] Think about empty arguments or a weird use of '\'
- [x] Do not try multiline strings
env
- [x] Check if env shows you the current environment variables
export
// export를 인자 없이 했을 때, env와는 차이가 있음. 앞에 declare -x가 붙나?
- [x] Export environment variables, create new ones and replace old ones
- [x] Check them with env
unset
- [x] Export environment variables, create new ones and replace old ones
- [x] Use unset to remove some of them
- [x] Check the result with env
Environment Variables
- [x] Execute echo with some $ variables as arguments
- [x] Check if double quotes around $ variables is working correctly (like in bash)
cd
- [x] Use the command cd to move the working directory and check if you are in the right directory with /bin/ls
- [x] Repeat multiple times with working and not working cd
- [x] try '.' '..' as arguments too
pwd
- [x] Use the command pwd
- [x] Repeat multiple times in multiple directories
- [x] try '.' '..' as arguments too
Relative Path
- [x] Execute commands but this time use a relative path
- [x] Repeat multiple times in multiple directories with complex relative path (lots of ..)
Environment Path
- [x] Execute commands but this time without any path. (ls, wc, awk etc...)
- [ ] Unset the $PATH and check if it is not working anymore
- [ ] Set the $PATH to a multiple directory value (directory1:directory2) and check that directories are checked in order from left to right
Simple Quotes
- [x] Execute commands with simple quotes as argument
- [x] Try empty arguments
- [x] Try environment variables, whitespaces and semicolons in the simple quotes
Redirection
- [x] Execute commands with redirections < and/or >
- [x] Repeat multiple times with different commands and arguments and sometimes change > with >>
- [x] Check if multiple of the same redirections fail
Pipes
- [x] Execute commands with pipes like 'cat file | grep bla | more'
- [x] Repeat multiple times with different commands and arguments
- [x] Try some failing commands like 'ls filethatdoesntexist | grep bla | more'
- [x] Try to mix pipes and redirections.
Go Crazy
- [x] Execute commands that should not work like 'dsbksdgbksdghsd' and check if the shell doesn't crash and prints an error
- [x] Try to execute a really really really long command with a ton of arguments
- [x] Have fun with that beautiful minishell and enjoy it