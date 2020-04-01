#include "complex.h"


int analysisArr[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000,0};
/*array that stores information about the complex*/
/*first cell - number of args.      second cell - command number.       third cell start index of command name.*/
/*forth cell - end index of command name.       fifth cell - first parameter.       sixth cell - start index of first parameter*/
/*seventh cell - end index of first parameter       eighth cell - second parameter      ninth - start index of second parameter*/
/*tenth cell - end index of second parameter         elevnth cell - third  parameter        twelveth cell - start index of third parameter*/
/*thirteenth cell - end index of third parameter*/



double realArgs[2] = {0, 0};

/*array that stores second and third parameter if they are real*/


int analysis_command(char command[]) {


    /*Error Massages*/
    /* 0-Everything Fine, No Errors.*/
    /* 1- Empty command, No Errors.*/
    /* 2-To Many parameters.*/
    /* 3-undefined command.*/
    /* 4-undefined complex.*/
    /* 5-missing parameter */
    /* 6-missing comma*/
    /* 7-Illegal comma*/
    /* 8-multiple consecutive comma*/
    /* 9-extra text*/
    /* 10-invalid parameter not a complex*/
    /* 11-invalid parameter not a number*/


    int comma = TRUE; /* flag for comma error*/
    analysisArr[0] = count_args(command);
    if (analysisArr[0] == 0) {
        /*if there are no arguments command is fine*/
        return 1;
    }
    analysis_command_name(command);
    if (analysisArr[1] == eror) {
        /*if error in command name*/
        return 3;
    } else if (analysisArr[0] > 4) {
        /* if three are two many arguments*/
        return 2;
    }
    if (!((count_commas(command) + 2 == analysisArr[0]) ||
          ((analysisArr[1] == stopp && analysisArr[0] == 1) && count_commas(command) == 0))) {
        /* if number of commas is wrong we check at the end what is the problem*/
        comma = FALSE;
    }

    if (analysisArr[0] == 1 && comma) {
        /*if there is one argument*/
        if (analysisArr[1] == stopp) {
            /*if the command is stop its OK*/
            return 0;
        } else {
            /*else its missing parameter*/
            return 5;
        }
    }
    if (analysisArr[1] > stopp) {
        /*if the command is not stop check what is the first argument*/
        analysis_first_parameter(command);
        if (analysisArr[4] < 0) {
            /*if first parameter has error*/
            if (analysisArr[4] == -1) {
                return 10;
            }
            if (analysisArr[4] == -2) {
                return 4;
            }
        }
    }
    if (analysisArr[0] == 2 && comma) {
        /*if there are two arguments*/
        if (analysisArr[1] < 4 && analysisArr[1] > 1) {
            /*if command is either abs or print*/
            return 0;
        } else if (analysisArr[1] < 2) {
            /*if command less than print*/
            return 2;
        } else {
            /*if command more than abs*/
            return 5;
        }
    }
    if (analysisArr[1] > absC && analysisArr[1] < multCR) {
        /*if bigger than abs and smaller than multCR the second parameter is  complex*/
        analysis_second_parameter_comp(command);
        if (analysisArr[7] < 0) {
            if (analysisArr[7] == -1) {
                return 10;
            }
            if (analysisArr[7] == -2) {
                return 4;
            }
        }
    } else if(analysisArr[1]>absC) {
        /*if bigger than multCC second parameter is real*/
        realArgs[0] = analysis_second_parameter_real(command);
        if (realArgs[0] == 10000) {
            return 11;
        }
    }
    if (analysisArr[0] == 3 && comma) {
        if (analysisArr[1] > absC && analysisArr[1] < read) {
            /*if command bigger than abs and smaller than read*/
            return 0;
        } else if (analysisArr[1] == read) {
            /*if command is read*/
            return 5;
        } else {
            /*command is abs or smaller*/
            return 2;
        }
    }
    realArgs[1] = analysis_third_parameter_real(command);
    if (realArgs[1] == 10000&&analysisArr[1]==read) {
        /*if the value is not a number*/
        return 11;
    }
    if (analysisArr[0] == 4 && comma) {
        if (analysisArr[1] == read) {
            return 0;
        } else {
            return 2;
        }
    }
    comma = check_commas(command);
    if (!comma) {
        return 9;
    }

    comma = check_commas(command);
    switch (comma) {
        case 1:
            return 8;
        case 2:
            return 7;
        default:
            return 9;
    }
    return 9;
}

void analysis_command_name(char command[]) {
    enum commands commandToReturn;
    char *start, *end;
    int length;
    length = 0;
    start = command;
    if (isspace(command[0]))
        /*find start of command name*/
        while (isspace(*start)) {
            start++;
        }
    end = start;
    while (isalpha(*end) || *end == '_') {
        /*find end of command*/
        end++;
        length++;
    }


    /* find what the command is*/


    if (strncmp("stop", start, length) == 0&&length==4) {
        commandToReturn = stopp;
    } else if (strncmp("print_comp",start,  length) == 0&&strlen("print_comp")==length) {
        commandToReturn = print;
    } else if (strncmp("abs_comp", start, length) == 0&&strlen("abs_comp")==length) {
        commandToReturn = absC;
    } else if (strncmp("add_comp", start, length) == 0&&strlen("add_comp")==length) {
        commandToReturn = add;
    } else if (strncmp("sub_comp",start,  length) == 0&&strlen("sub_comp")==length) {
        commandToReturn = sub;
    } else if (strncmp("mult_comp_comp",start,  length) == 0&&strlen("mult_comp_comp")==length) {
        commandToReturn = multCC;
    } else if (strncmp("mult_comp_real",start,  length) == 0&&strlen("mult_comp_real")==length) {
        commandToReturn = multCR;
    } else if (strncmp("mult_comp_img",start,  length) == 0&&strlen("mult_comp_img")==length) {
        commandToReturn = multCI;
    } else if (strncmp( "read_comp",start, length) == 0&&strlen("read_comp")==length) {
        commandToReturn = read;
    } else {
        commandToReturn = eror;
    }
    analysisArr[1] = commandToReturn;
    analysisArr[2] = start - command;
    analysisArr[3] = end - command;
}

int count_commas(char command[]) {
    int i, count;
    for (i = 0, count = 0; command[i]; i++)
        count += (command[i] == ',');
    return count;
}

int count_args(char command[]) {
    int count, state;
    count = state = FALSE;
    while (*command) {
        if (*command == ' ' || *command == '\n' || *command == '\t' || *command == ',') {
            state = FALSE;
        } else if (state == FALSE) {
            state = TRUE;
            ++count;
        }
        ++command;
    }
    return count;
}

void analysis_first_parameter(char command[]) {
    /*Error Massages*/
    /*-1 - invalid parameter not complex.*/
    /*-2 - Undefined complex*/
    char *start, *end;
    int valueToReturn;
    int length = 0;
    start = command + analysisArr[3];
    while (isspace(*start) || *start == ',') {
        /*find start of command name*/
        start++;
    }
    end = start;
    while (isalpha(*end) || isdigit(*end)) {
        /*find end of command*/
        end++;
        length++;
    }
    if (length > 1) {
        valueToReturn = -1;
    } else if (*(start) == 'A') {
        valueToReturn = 0;
    } else if (*(start) == 'B') {
        valueToReturn = 1;
    } else if (*(start) == 'C') {
        valueToReturn = 2;
    } else if (*(start) == 'D') {
        valueToReturn = 3;
    } else if (*(start) == 'E') {
        valueToReturn = 4;
    } else if (*(start) == 'F') {
        valueToReturn = 5;
    } else {
        valueToReturn = -2;
    }
    analysisArr[5] = start - command;
    analysisArr[6] = end - command;
    analysisArr[4] = valueToReturn;
}

void analysis_second_parameter_comp(char command[]) {
    char *start, *end;
    int valueToReturn;
    int length = 0;
    start = command + analysisArr[6];
    while (isspace(*start) || *start == ',') {
        /*find start of command name*/
        start++;
    }
    end = start;
    while (isalpha(*end) || ispunct(*end) || isdigit(*end)) {
        /*find end of command*/
        end++;
        length++;
    }
    if (length > 1) {
        valueToReturn = -1;
    } else if (*(start) == 'A') {
        valueToReturn = 0;
    } else if (*(start) == 'B') {
        valueToReturn = 1;
    } else if (*(start) == 'C') {
        valueToReturn = 2;
    } else if (*(start) == 'D') {
        valueToReturn = 3;
    } else if (*(start) == 'E') {
        valueToReturn = 4;
    } else if (*(start) == 'F') {
        valueToReturn = 5;
    } else {
        valueToReturn = -2;
    }
    analysisArr[7] = valueToReturn;
    analysisArr[8] = start - command;
    analysisArr[9] = end - command;
}

double analysis_second_parameter_real(char command[]) {
    /*Error Massages*/
    /*-1 - invalid parameter not number.*/
    char *start, *end;
    double value;
    start = command + analysisArr[6];
    while (*start == ',' || isspace(*start)) {
        /*find start of command name*/
        start++;
    }
    value = strtod(start, &end);
    analysisArr[8] = start - command;
    analysisArr[9] = end - command;
    if (!(isdigit(*start) || *start == '-')) {
        return 10000;
    }
    return value;
}

double analysis_third_parameter_real(char command[]) {
    /*Error Massages*/
    /*-1 - invalid parameter not number.*/
    /*Error Massages*/
    /*-1 - invalid parameter not number.*/
    char *start, *end;
    double value;
    start = command + analysisArr[9];
    while (*start == ',' || isspace(*start)) {
        /*find start of command name*/
        start++;
    }
    value = strtod(start, &end);
    analysisArr[10] = start - command;
    analysisArr[11] = end - command;
    if (!(isdigit(*start) || *start == '-')) {
        return 10000;
    }
    return value;
}

int check_commas(char command[]) {
    /*Return Massages*/
    /*0-comma is fine*/
    /*1-multiple consecutive comma*/
    /*2-Illegal comma*/
    /*3-missing comma*/
    /*4-extra text*/
    int numOfCommas=count_commas(command);
    if (analysisArr[0] < 3 && numOfCommas == 0) {
        return 0;
    } else if (numOfCommas + 2 < analysisArr[0]) {
        return 3;
    }
    if ((strrchr(command, ',') - command) > analysisArr[analysisArr[0] * 3]) {
        return 4;
    }
    if ((strchr(command, ',') - command) <= analysisArr[3]) {
        return 2;
    }
    return 1;

}

void call_func(comp *ptrs[]) {
    enum commands command = analysisArr[1];
    if (command == stopp)
        stop();
    if (command == print)
        print_comp(ptrs[analysisArr[4]]);
    if (command == absC)
        abs_comp(ptrs[analysisArr[4]]);
    if (command == add)
        add_comp(ptrs[analysisArr[4]], ptrs[analysisArr[7]]);
    if (command == sub)
        sub_comp(ptrs[analysisArr[4]], ptrs[analysisArr[7]]);
    if (command == multCC)
        mult_comp_comp(ptrs[analysisArr[4]], ptrs[analysisArr[7]]);
    if (command == multCR)
        mult_comp_real(ptrs[analysisArr[4]], realArgs[0]);
    if (command == multCI)
        mult_comp_img(ptrs[analysisArr[4]], realArgs[0]);
    if (command == read)
        read_comp(ptrs[analysisArr[4]], realArgs[0], realArgs[1]);


}
