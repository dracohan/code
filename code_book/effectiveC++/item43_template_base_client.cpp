#include "item43_template_base.h"

class CompanyA{

};

int main() {
  LoggingMsgSender<CompanyA> lms;
  lms.sendClearMsg();
}