#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//指针是一个变量，用于存放内存单元的地址 
//指针的类型是可以是char*,short*,int*......都可以存储地址，指针大小都是4个字节
//但是解引用操作的时候权限不一样，指针类型决定了可以操作的字节大小
//指针加减一个整数时的结果也不一样，int*的指针地址+1是相隔4个字节，char*的指针地址+1相隔1个字节
//指针的大小为4个字节（32位机器）或者8个字节（64位机器）
//32位机器上有32根线，每一个地址有32个比特位，1个字节是8个比特位，所以一个地址需要4个字节来表示
//野指针：未被初始化的指针，系统会赋予它随机的地址，通过解引用去操作很危险，因为不知道修改的是哪个地址的值
//野指针：越界的指针也会变成野指针，比如数组的指针不断++，访问到数组最后一个元素之后再++就会变成野指针
//野指针：指针原来所指向地址的内存空间释放了（例如局部变量，出了作用域局部后，变量的空间就会还给系统），指针也会变成野指针
//如果创建指针的时候实在不知道赋什么值，可以初始化为int* p=NULL; 此时指针p不指向任何地址，如果原来的内存释放了，还想继续保留指针，也可以把它赋值为NULL以保留

//int main()
//{
//	int a = 0x11223344; //16进制数字11223344
//	int *pa = &a;
//	char* pc = &a; //两个类型的指针都能存储a的地址
//	//*pa = 0;
//	//*pc = 0;       //但是通过解引用*pa可以改变a里面4个字节的值，但通过*pc只能改变a里面第1个字节的值，因为char*只有改一个字节的权限
//	printf("%p\n", pa);
//	printf("%p\n", pa+1); //跳了1个整型，4个字节
//	printf("%p\n", pc);
//	printf("%p\n", pc+1); //跳了1个字节
//	return 0;
//}


//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr; //指针p存放的只是数组的第一个元素的地址
//	int i = 0;
//	for (i = 0; i < 10; i++)  //把数组里的每个数都改为1
//	{
//		*(p + i) = 1;
//	}
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("%d\n", &arr[9] - &arr[0]); //指针减去指针，得到的结果是两个指针之间需要跳跃的次数
//	return 0;
//}

//#define N_VALUES 5
//float values[N_VALUES]; //创建数组values，元素个数是5
//float* vp;
//for (vp = &values[0]; vp < &values[N_VALUES])
//{
//	*vp++ = 0; //先解引用，把第一个元素的值改为0，然后vp++指针右移，再循环，最终5个元素都改成了0
//}

//int my_strlen(char* str)
//{
//	char* start = str;
//	char* end = str;
//	while (*end != '\0')
//	{
//		end++;
//	}
//	return (end - start);
//}
//int main()
//{
//	char arr[] = "bit";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}

//&数组名，sizeof(数组名)
//只有以上两种情况下，数组名表示的是整个数组，其他情况出现的数组名表示的只是第一个元素的地址
//int main()
//{
//	int arr[10] = { 0 };
//	printf("%p\n", &arr); //取出的是整个数组的地址
//	printf("%p\n", &arr[0]); //结果同上，说明对整个数组取出的地址跟数组第一个元素的地址是相等的，但意义不同，分别+1之后就不相等了
//	printf("%p\n", arr); //取出的是首元素的地址
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	int* * ppa = &pa; //ppa就是二级指针，存放的是指针pa的地址
//	**ppa = 20;        //解引用2次，修改a的值
//	printf("%d\n", **ppa); //解引用2次，打印出a的值，也就是10
//	return 0;
//}

int main()
{
	int a = 10;
	int b = 20;
	int c = 30;
	//int* pa = &a;
	//int* pb = &b;
	//int* pc = &c;
	int* arr[3] = { &a, &b, &c }; //arr是指针数组，用于存放指针，其实是a，b，c的地址
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("%d ", *(arr[i])); //将指针数组里的三个元素（指针/地址）解引用，打印出a，b，c的值
	}
	return 0;
}