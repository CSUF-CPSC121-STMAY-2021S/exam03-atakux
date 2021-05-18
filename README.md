# Final Exam

## Rules of Behavior
1. Do not communicate with anyone during the exam (no email, no social media, no texting, no phones, no talking, no passing notes, no internet communicating).  If there is any evidence of communicating with anyone during the exam you will receive a zero.
1. You **must** turn off your cell phone and store it away.
1. Your submission **must** be solely you own work without the assistance of anyone by any means.
1. All programming code **must** be written in C++.
1. You **must** use Tuffix to compile your program.
1. All your code **must** be pushed to Github by **8:50 p.m. today**.  Any submissions after that time will not be considered.
1. You may use your book.
1. You may use the Internet as a **reference only**.
1. If you have questions, raise your hand in Zoom, **DO NOT USE YOUR MICROPHONE DURING THE EXAM**.

## Getting Started
1. Open the Terminal program in Tuffix.
1. Change the present working directory to the `Documents` directory by typing the following command at the command prompt:

    ```
    cd Documents
    ```

1. Make a copy of this Github repository on your computer using the `git` and `clone` commands that you will input to the terminal. The commands take a URL as a parameter to specify where it can get a copy of the repository. You can find the URL by clicking on the green *Clone or download* button at the top right part of this page. Copy the URL and replace the example text shown below. Note that `username` should be replaced with your own Github username. When you hit <kbd>Enter</kbd> it will ask you to provide your Github username and password. Once done, you will have a copy of the repository on your computer.
    ```
    git clone https://github.com/CSUF-CPSC121-STMAY-2021S/exam03-username.git
    ```
1. Navigate into the new directory using the command line. Note that `username` should be replaced with your own Github username.  As a shortcut, you can type the first few letters of the folder name and press <kbd>Tab</kbd> so that it auto completes the folder name for you.

     ```
     cd exam03-username
     ```
     
## Instructions
1. Title Comment Block
     1. Create your source code file named `main.cpp`, and at the very top of the source code use three one line comments to document your name, date, and the exercise, using the following format:
          <pre>Name: <i>Stephen May</i><br>Date: 5/9/2021<br>Exercise: Exam03 Solution</pre>

1. Write a C++ program that performs as a Tuffy Titan Reservation Program which simply prompts the user to enter a new name, military time, and phone number for the reservation, and then lists the contents of the reservations in chronological order.  NOTE: You may use the following snippet of code to display the military time in regular format:
    ```
    string displayTime (unsigned short t){

        unsigned short hour = t / 100;
        unsigned short minutes = t % 100;

        string strMinutes;
        if(minutes >= 10)
            strMinutes = to_string(minutes);
        else
            strMinutes = "0"+to_string(minutes);

        string strHour;
        if(hour == 0)
            strHour = "12";
        else if(hour < 13)
            strHour = to_string(hour);
        else
            strHour = to_string(hour - 12);

        string strAMPM;
        if(hour < 12)
            strAMPM = "am";
        else
            strAMPM = "pm";

        return strHour+":"+strMinutes+strAMPM;

    }
    ```

1. Your Person class should meet the following requirements:
     1. Declare a `Person` class in a specification file named `person.hpp`.
     1. Define all member functions that are not inline member functions in an implementation file named `person.cpp`.
     1. Declare a constructor member function that initializes the member variable for name to an empty string, the member variable for the military time to 0, and the member variable for the phone number to an empty string.
    1. Declare a public member function named `setName` to set the value of the member variable for the name.
    1. Declare a public member function named `setTime` to set the value of the member variable for the military time.  The function should validate the input to ensure the hour is between 0 and 23, and the that minutes are between 0 and 59.  If the input is not valid the value stored should be set to 0.
    1. Declare a public member function named `setPhone` to set the value of the member variable for the phone number.
    1. Declare a public member function named `getName` to return the value of the member variable for the name.
    1. Declare a public member function named `getTime` to return the value of the member variable for the military time.
    1. Declare a public member function named `getPhone` to return the value of the member variable for the phone number.

1. Your Reservation class should meet the following requirements:
     1. Declare a `Reservation` class in a specification file named `reservation.hpp`.
     1. Define all member functions that are not inline member functions in an implementation file named `reservation.cpp`.
     1. Declare a constructor member function that initializes a member variable to zero which will keep track of the number of elements in a dynamically allocated array, and initializes a member variable Person pointer to the null pointer.
     1. Declare a public member function named `addPerson` which takes a string name, unsigned short military time, and string phone number, instantiates a Person object, and adds the object to an array of Persons and sorts the array in chronological order based on the military time.  Your class should implement dynamic memory allocation to accommodate any size array.  Since this function would be increasing the array size by one, your class would most likely follow the below steps:
          1. dynamically allocate a temporary array with the increased size
          1. copy the contents from the array pointed to by the member variable Person pointer to the temporary array
          1. add the new data to the temporary array
          1. delete the memory associated with the array pointed to by the member variable Person pointer
          1. assign the temporary array to the member variable Person pointer
          1. increase the number of elements member variable
          1. sort the array pointed to by the member variable Person pointer
     1. Declare a public member function named `getCount` to return the number of array elements.
     1. Declare a public member function named `getName` to return the name given an element number.  The function should return an empty string if the element number given is larger than the number of elements in the array.
     1. Declare a public member function named `getTime` to return the military time given an element number.  The function should return 0 if the element number given is larger than the number of elements in the array.
     1. Declare a public member function named `getPhone` to return the phone number given an element number.  The function should return an empty string if the element number given is larger than the number of elements in the array.
     1. Declare a destructor member function that deletes the memory associated with the array of Persons.

1. Compile the file using the command below. The `-std` option tells the compiler that it will use C++ version 17 standards and the `-o main` option tells the compiler to place the executable code into a file called `main`.

    ```
    clang++ -std=c++17 main.cpp person.cpp reservation.cpp -o main
    ```
1. Run the program using the command below and repeat the steps above until you are satisfied your program output meets the above requirements.  I strongly suggest that you run your program using the sample output below and ensure that all blank lines and new lines are exactly as below.

    ```
    ./main
    ```


1. Typical input and output for the program:
     ```
    *** TUFFY TITAN RESERVATION PROGRAM ***

    Enter new name or 'exit': Thor

    Enter military time: 1715

    Enter phone: (626)987-4321

    Time                Name                Phone               
    ============================================================
    5:15pm              Thor                (626)987-4321       

    Enter new name or 'exit': Captain America

    Enter military time: 1145

    Enter phone: (714)555-1212

    Time                Name                Phone               
    ============================================================
    11:45am             Captain America     (714)555-1212       
    5:15pm              Thor                (626)987-4321       

    Enter new name or 'exit': Black Widow

    Enter military time: 2130

    Enter phone: (909)222-2468

    Time                Name                Phone               
    ============================================================
    11:45am             Captain America     (714)555-1212       
    5:15pm              Thor                (626)987-4321       
    9:30pm              Black Widow         (909)222-2468       

    Enter new name or 'exit': Hulk

    Enter military time: 1400

    Enter phone: (562)123-4567

    Time                Name                Phone               
    ============================================================
    11:45am             Captain America     (714)555-1212       
    2:00pm              Hulk                (562)123-4567       
    5:15pm              Thor                (626)987-4321       
    9:30pm              Black Widow         (909)222-2468       

    Enter new name or 'exit': exit
     ```

1. Run the unit testing program to ensure that your program runs as expected using predefined user input.

    ```
    make test
    ```
    
    <i>Note: You will be prompted to install the cmake program the first time you run the make test command on the device you are working on.  Answer `Yes` to install the program, and you will need to enter the Tuffix superuser (sudo) password, which should be `student`. After you have installed the cmake program, run the `make test` command again.</i>
    
    The unit testing will output the results of a series of tests using specific input and expected output.  Any error will stop the unit testing and will provide information on where the expected output is different from the actual output.  You will need to edit your source code to fix the error, recompile your program, and run `make test` repeatedly until it passes all the test.

## Submission
Periodically throughout the exercise, and when you have completed the exercise, **submit the complete repository to Github**.

   <pre>git add .<br>git commit -m "<i>your comment</i>"<br>git push</pre>

In case it asks you  to configure global variables for an email and name, just copy the commands it provides then replace the dummy text with your email and Github username.

   <pre>git config --global user.email "<i>tuffy@csu.fullerton.edu</i>"<br>git config --global user.name "<i>Tuffy Titan</i>"<br>git commit -m "<i>your comment</i>"<br>git push</pre>

When you completed the final Github push, go back into github.com through the browser interface and ensure all your files have been correctly updated.  You should have the following files:
    <pre>main.cpp<br>main<br>person.hpp<br>person.cpp<br>reservation.hpp<br>reservation.cpp<br>unittest.xml (in the test folder)</pre>
    
## Grading
1. All points add up to a total of 100 points possible as detailed below.  Partial credit will be given where applicable.

| Points | Description |
| --- | --- |
|50|initial git clone of this repository to your Tuffix machine|
|5|main.cpp file submitted contains the main program structure and meets the program requirements|
|5|main executable file submitted runs without crashing|
|5|person.hpp file submitted contains the Person class declaration and meets the program requirements|
|5|person.cpp file submitted contains the Person class member functions and meets the program requirements|
|5|reservation.hpp file submitted contains the Reservation class declaration and meets the program requirements|
|5|reservation.cpp file submitted contains the Reservation class member functions and meets the program requirements|
|20|unit testing results submitted pass each test|
