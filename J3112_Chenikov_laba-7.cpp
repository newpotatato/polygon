class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = password.size();

        //Создание флагов для каждого условия
        bool hasLower = false;
        bool hasUpper = false;
        bool hasDigit = false;

        //Жадная проверка на удовлетворение условий
        for (char c : password) {
            if (islower(c)) hasLower = true;
            if (isupper(c)) hasUpper = true;
            if (isdigit(c)) hasDigit = true;
            if (hasLower==true && hasUpper == true && hasDigit == true){
                break;
            }
        }

        int missingTypes = !hasLower + !hasUpper +!hasDigit;

        //Проверка на последовательность символов 
        int replace = 0;
        int oneSeq = 0;
        int twoSeq = 0;
        for (int i = 2; i < n; ++i) {
            if (password[i] == password[i - 1] && password[i] == password[i - 2]) {
                int length = 2;
                while (i < n && password[i] == password[i - 1]) {
                    ++length;
                    ++i;
                }
                replace += length / 3;
                if (length % 3 == 0) ++oneSeq;
                else if (length % 3 == 1) ++twoSeq;
            }
        }

        if (n < 6) return max(missingTypes, 6 - n);
        if (n <= 20) return max(missingTypes, replace);

        //Высчитывание количества символов для удаления последовательностей
        int deleteCount = n - 20;
        replace -= min(deleteCount, oneSeq);
        replace -= min(max(deleteCount - oneSeq, 0), twoSeq * 2) / 2;
        replace -= max(deleteCount - oneSeq - 2 * twoSeq, 0) / 3;

        return deleteCount + max(missingTypes, replace);
    }
};
