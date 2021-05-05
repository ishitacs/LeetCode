 class Solution {
public:
    int strongPasswordChecker(string password) {
        int l = password.length();
        int add = count2(password);
        int del = 0;
        int replace = 0;
        if (l < 6) {
            if (6 - l > add) {
                add = 6 - l;
            }
        } else if (l > 20) {
            del = l - 20;
            if (del >= add) {
                replace = add;
                add = 0;
                del = del - add;
            } else {
                replace = del;
                del = 0;
                add = add - del;
            }
        } else {
            replace = add;
            add = 0;
        }
        std::cout << "STAT " << password.length() << " " << add << " " << del << " " << replace << std::endl;
        if (add > 0) {
            return add + std::max(handle_add(password, add), replace);
        } else {
            return del + std::max(handle_delete(password, del), replace);
        }
      }
      
      int count2(string password) {
            bool has_lower = false;
            bool has_upper = false;
            bool has_digit = false;
            for (size_t i = 0; i < password.length(); ++i) {
                if (std::islower(password[i])) {
                    has_lower = true;
                }
                if (std::isupper(password[i])) {
                    has_upper = true;
                }
                if (std::isdigit(password[i])) {
                    has_digit = true;
                }
            }
            return 3 - (has_lower + has_upper + has_digit);
      }
    
    int handle_add(string password, int add) {
        int needed[3] = {0};
        int n = 1;
        for (size_t i = 1; i <= password.length(); ++i) {
            if (i < password.length() && password[i] == password[i - 1]) {
                n++;
            } else {
                if (n > 2 && n % 3 == 1) {
                    if (add > 0) {
                        n -= 2;
                        add--;
                    }
                    if (n > 2) {
                        needed[n % 3] += n / 3;
                    }
                }
                n = 1;
            }
        }
        n = 1;
        for (size_t i = 1; i <= password.length(); ++i) {
            if (i < password.length() && password[i] == password[i - 1]) {
                n++;
            } else {
                if (n > 2 && n % 3 == 0) {
                    if (add > 1 && n >= 6) {
                        n -= 4;
                        add-=2;
                    } else if (add >0 && n < 6) {
                        n -= 2;
                        add--;
                    }
                    if (n > 2) {
                        needed[n % 3] += n / 3;
                    }
                }
                n = 1;
            }
        }
        n = 1;
        for (size_t i = 1; i <= password.length(); ++i) {
            if (i < password.length() && password[i] == password[i - 1]) {
                n++;
            } else {
                if (n > 2 && n % 3 == 2) {
                    needed[n % 3] += n / 3;
                }
                n = 1;
            }
        }
        cout << needed[0] << " " << needed[1] << " " << needed[2] << " " << add << std::endl;
        return needed[0] + needed[1] + std::max(0, needed[2] - (add * 2 / 3));
    }
    
    int handle_delete(string password, int del) {
        int needed[3] = {0};
            int n = 1;
            for (size_t i = 1; i <= password.length(); ++i) {
                if (i < password.length() && password[i] == password[i - 1]) {
                    n++;
                } else {
                    if (n > 2 && n % 3 == 0) {
                        if (del > 0) {
                            n -= 1;
                            del--;
                        }
                        if (n > 2) {
                            needed[n % 3] += n / 3;
                        }
                    }   
                    n = 1;
                }
            }
        n = 1;
        for (size_t i = 1; i <= password.length(); ++i) {
            if (i < password.length() && password[i] == password[i - 1]) {
                n++;
            } else {
                if (n > 2 && n % 3 == 1) {
                    if (del > 1) {
                        n -= 2;
                        del-=2;
                    }
                    if (n > 2) {
                        needed[n % 3] += n / 3;
                    }
                }       
                n = 1;
            }
        }
        n = 1;
        for (size_t i = 1; i <= password.length(); ++i) {
            if (i < password.length() && password[i] == password[i - 1]) {
                n++;
            } else {
                if (n > 2 && n % 3 == 2) {
                    needed[n % 3] += n / 3;
                }
                n = 1;
            }
        }
        return needed[0] + needed[1] + std::max(0, needed[2] - (del / 3));
    }
};