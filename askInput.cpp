string askInput(){
    /*
    Function prototype:
    string askInput();

    Function Description:
    This method asks the user for input
    Spaces are not excluded, so the input string can contain a space

    Example:
    String input;
    input = askInput();

    Pre-condition:
    A string variable to store the return value of the function needs to be initialized

    Post-condition:
    the inputed string will be returned
    */

	char input[100];
	string inputString;
	cin >> inputString;
	cin.getline(input,100);
	inputString += string(input);

	return inputString;
}