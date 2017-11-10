#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long tobyte_deobf(char* input) {
	for (int i = 0, len = 0, err = 0, t_len = 0, n_len = 0;; i++)
		if ((len++ && input[i + 1] == '\0') && (((len < 2 || (input[0] < 48 || input[0] > 57) || (!(input[len - 2] == 'K' || input[len - 2] == 'M' || input[len - 2] == 'G' || input[len - 2] == 'T' || (input[len - 2] > 47 && input[len - 2] < 58))) || (input[len - 1] != 'B')) && (err = -1)), i = 0, 1))
			for (char *num_a = calloc(len, sizeof(char)), *type_a = calloc(2, sizeof(char));; num_a[n_len++] = input[i], i++) 
				if (i >= len || input[i] < 48 || input[i] > 57)
					for (i = n_len;; type_a[t_len++] = input[i], i++) 
						if ((i >= len || (input[i] > 47 && input[i] < 58)) && ((i = 0, 1) || ((t_len + n_len != len) && (err = -1))))
							for (long long type = (type_a[0] == 'B') ? pow(2, 0) : (type_a[0] == 'K') ? pow(2, 10) : (type_a[0] == 'M') ? pow(2, 20) : (type_a[0] == 'G') ? pow(2, 30) : pow(2, 40), num = 0, retval;; num += (num_a[n_len - i - 1] - '0') * pow(10, i), i++) 
								if ((i >= n_len) && (retval = num * type, free(num_a), free(type_a), 1))
									return (retval < 0 || err == -1) ? -1 : retval;
}

long long tobyte_obf(char* input) {
	for (int i = 0, len = 0, err = 0, t_len = 0, n_len = 0;; i++) if ((len++ && input[i + 1] == '\0') && (((len < 2 || (input[0] < 48 || input[0] > 57) || (!(input[len - 2] == 'K' || input[len - 2] == 'M' || input[len - 2] == 'G' || input[len - 2] == 'T' || (input[len - 2] > 47 && input[len - 2] < 58))) || (input[len - 1] != 'B')) && (err = -1)), i = 0, 1)) for (char *num_a = calloc(len, sizeof(char)), *type_a = calloc(2, sizeof(char));; num_a[n_len++] = input[i], i++) if (i >= len || input[i] < 48 || input[i] > 57) for (i = n_len;; type_a[t_len++] = input[i], i++) if ((i >= len || (input[i] > 47 && input[i] < 58)) && ((i = 0, 1) || ((t_len + n_len != len) && (err = -1)))) for (long long type = (type_a[0] == 'B') ? pow(2, 0) : (type_a[0] == 'K') ? pow(2, 10) : (type_a[0] == 'M') ? pow(2, 20) : (type_a[0] == 'G') ? pow(2, 30) : pow(2, 40), num = 0, retval;; num += (num_a[n_len - i - 1] - '0') * pow(10, i), i++) if ((i >= n_len) && (retval = num * type, free(num_a), free(type_a), 1)) return (retval < 0 || err == -1) ? -1 : retval;
}

char* tab_char(char* x) {
	int len;
	for (len = 0; x[len] != '\0'; len++);
	char* retval = calloc(len / 8 + 10, sizeof(char));
	for (int i = 0, m = 3; m > len / 8 + 1; i++, m--) retval[i] = '\t';
	return retval;
}

int main() {
	char *tmp, inputs[50][100] = {"2B", "3KB", "9MB", "4GB", "7TB", "1234567TB", "12345678TB", "0B", "23MB", "478192KB", "732GB", "B", "GB", "MB4", "", "4.2MB"};
	for (int i = 0; i < 15; i++) {
		tmp = tab_char(inputs[i]);
		printf("%s:%s%lli\n", inputs[i], tmp, tobyte_obf(inputs[i]));
		free(tmp);
	}
}
