//Work_On,,,

#include <iostream>

class Date {
private:
	int year_;
	int month_;
	int day_;
public:
	void SetDate(int year, int month, int date) {
		year_ = year;
		month_ = month;
		day_ = date;
	}
	void AddDay(int inc) {
		int temp;
		temp = day_ + inc;
		
		if(month_ == (1 || 3 || 5 || 7 || 8 || 10 || 12)) {
			if(temp > 31) {
				month_++;
				day_ = temp - 31;
			} else {
				day_ += inc;
			}
		} else if (month_ == 2) {
			if(temp > 28) {
				month_++;
				day_ = temp - 28;
			} else {
				day_ += inc;
			}
		} else {
			if(temp > 30) {
				month_++;
				day_ = temp - 30;
			} else {
				day_ += inc;
			}
		}
	}
	void AddMonth(int inc) {
		int temp;
		temp = month_ + inc;
		if(temp > 12) {
			year_++;
			month_ = temp - 12;
		} else {
			month_ = temp;
		}
	}
	void AddYear(int inc) {
		year_ += inc;
	}
	
	void ShowDate() {
		std::cout << year_ << "년 " << month_ << "월 " << day_ << "일" << std::endl;
	}
};

int main() {
	Date today;
	today.SetDate(2020, 10, 31);
	today.ShowDate;
	today.AddYear(3);
	today.ShowDate;
	today.AddMonth(3);
	today.ShowDate;
	today.AddDay(3);
	today.ShowDate;
	
	return 0;
}