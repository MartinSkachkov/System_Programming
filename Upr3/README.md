
# Упражнение 3

1.  Напишете програма, която създава файла **fff** и го отваря три пъти:
    

-   само за четене през fd1
    
-   само за писане през fd2
    
-   за четене и писане през fd3
    

	След това:

	А)

	-   през fd2 записва “Hello world” в него
    
	-   през fd3 прочита 6 байта и изписва прочетеното на стандартния изход
    
	-   през fd1 прочита 5 байта и изписва прочетеното на стандартния изход
    
	-   през fd3 записва “chil” в него
    
	-   през fd2 записва “!!!”  в него
    
	-   през fd1 прочита 9 байта и изписва прочетеното на стандартния изход
    

	Б)

	-   през fd3 записва “Hello” в него
    
	-   през fd2 записва „worlds” в него
    
	-   през fd1 прочита 6 байта и изписва прочетеното на стандартния изход
    
	-   затваря fd2
    
	-   през fd3 записва “oops”  в него
    
	-   през fd1 прочита 6 байта и изписва прочетеното на стандартния изход
    

	Какво ще се изпише на стандартния изход и какво ще бъде съдържанието на файла във всеки от горните случаи?

  

  

2.  В текущата директория се намира файл **f1**  със съдържание:
    

	abcd-abcd-abcd

	Отворете файла с 2 различни дескриптора за четене и писане. Започвайки от последните 2 символа 			напишете думата **wxyz**. Запишете върху 5 и 6-тия символ от началото на файла - цифрите 1  и 2. Отпечатайте цялото съдържание на файла.

  

3.  Да се напише програма на Си, която получава като параметри в командния ред число и име на файл. Програмата извежда на стандартиния изход съдържанието на файла от указания от числото ред.
    

  

  

  

	 [](https://emojipedia.org/question-mark)

### ❓Трасировки:
    

-   Какво ще бъде изведено на стандартиня изход след успешното изпълнение на програмата /home/KN/SYSPROG/LAST/tras_1.
    

  

-   Във файла ffff има следната информация I am a student!. Какво ще бъде изведено на стандартния изход и какво ще е съдържанието на файла ffff след успешното изпълнение на програмата /home/KN/SYSPROG/LAST/tras_2.
    

  

4.  Да се състави програма на Си, която получава два параметъра, първият от които е име на съществуващ текстов файл, в който дължината на редовете не надвишава 60. Програмата извежда на стандартния изход онези от редове от текстовия файл, чийто последен символ е $. Създава файл с име втория параметър и в него записва - всеки път на нов ред – само цифрите, от всеки от останалите редове от първия файл. Извежда броя на редовете от новосформирания файл.

  