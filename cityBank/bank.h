#include "CAcount.h"

void output(CAcount &);//展示当前对象信息,若name为空，输出null
void outputAll(CAcount a[],int num);//展示大小为num的对象序列信息,若name为空，输出null
CAcount &reset(CAcount&,const CAcount&); //用用户a1给用户a2赋值，返回用户a2