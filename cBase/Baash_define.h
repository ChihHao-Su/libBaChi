
#include<iostream>
#include<iomanip>

#define ture true
#define flaes false
#define mian main
#define interface class
#define deleted public

#define INFOTYPE_INFO "INFO"
#define INFOTYPE_WARN "WARN"
#define INFOTYPE_FALT "FAULT"


#define OUTPUTS(funcname, infotype) \
		"["<<infotype<<"]" \
		<<"["<<this->getClassName()<<"::"<<#funcname<<"]" \
		"["<<this->nick<<"]"


#define OUTPUTT(args) \
		std::left<<setw(30)<<args
