
int are_identical(int snow1[], int snow2[]);
int identical_right(int snow1[], int snow2[], int start);
int identical_left(int snow1[], int snow2[], int start);

int main() {

}

/*
* snow1: a snowflake represented by an array of 6 numbers
* snow2: a snowflake represented by an array of 6 numbers
*/
int are_identical(int snow1[], int snow2[]) {
    for (int start = 0; start < 6; start++) {
        if (identical_right(snow1, snow2, start)) {
            return 1;
        }

        if (identical_left(snow1, snow2, start)) {
            return 1;
        }
    }
    return 0;
}

/*
* snow1: a snowflake represented by an array of 6 numbers
* snow2: a snowflake represented by an array of 6 numbers
* start: the starting index of snow2
*
* returns:
*   0 if snow1 and snow2 don't match
*   1 if snow1 and snow2 match
**/
int identical_right(int snow1[], int snow2[], int start) {
    for (int offset = 0; offset < 6; offset++) {
        // using mod 6 will always wrap snow2's index around between 0 - 5
        if (snow1[offset] != snow2[(start + offset) % 6]) {
            return 0;
        }
    }

    return 1;
}

/*
* snow1: a snowflake represented by an array of 6 numbers
* snow2: a snowflake represented by an array of 6 numbers
* start: the starting index of snow2
*
* returns:
*   0 if snow1 and snow2 don't match
*   1 if snow1 and snow2 match
**/
int identical_left(int snow1[], int snow2[], int start) {
    int snow2_index;

    for (int offset = 0; offset < 6; offset++) {
        snow2_index = start - offset;

        // if offset < 0, need to wrap around to other side of array
        if (snow2_index <= -1) {
            snow2_index = snow2_index + 6;
        }
        
        if (snow1[offset] != snow2[snow2_index]) {
            return 0;
        }
    }

    return 1;
}
