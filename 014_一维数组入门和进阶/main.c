#include <stdio.h>
#include <string.h>
#define LEN 10

/**
 * 一维数组的定义
 * 一维数组的长度
 * 一维数组的两个属性
 * 不同数据类型数组中每一个元素在内存中的物理地址
 */

/**
 * 一维数组的定义
 */
void DefineOneDimensionalArrayTest()
{
    //错误的定义数组的方法
    int n = 3;
    //错误定义,n必须为一个常量
    //int arr_1[n] = {1,2,3};

    //正确定义:方式一
    int arr_2[3];
    //正确定义:方式二
    int arr_3[LEN] = { 1,2,3 };
    //正确定义:方式三
    int arr_4[3] = { 1,2,3 };

    //定义一个未知大小的整形数组
    int nums_1[] = { 1,2,3,4,5 };
    int l1 = sizeof(nums_1) / sizeof(nums_1[0]);
    printf("数组长度:%d\n", l1);
    for (int i = 0; i < l1; i++)
    {
        printf("%d\n", nums_1[i]);
    }
    printf("--------------------------------\n");

    //定义一个已知大小的整形数组
    int nums_2[5] = { 1,2,3,4,5 };
    int l2 = sizeof(nums_2) / sizeof(nums_2[0]);
    printf("数组长度:%d\n", l2);
    for (int i = 0; i < l2; i++)
    {
        printf("%d\n", nums_2[i]);
    }
    printf("--------------------------------\n");

    //定义一个已知大小的整形数组
    int nums_3[5];
    int l3 = sizeof(nums_3) / sizeof(nums_3[0]);
    printf("数组长度:%d\n", l3);
    for (int i = 0; i < l3; i++)
    {
        printf("%d\n", nums_3[i]);
    }
    printf("--------------------------------\n");


    //数组长度为5,里面只包含三个元素,第4个和第5个元素因为没有被初始化,所以为值为0
    int nums_4[5] = { 1,2,3 };
    int l4 = sizeof(nums_4) / sizeof(nums_4[0]);
    printf("数组长度:%d\n", l4);
    for (int i = 0; i < l4; i++)
    {
        printf("%d\n", nums_4[i]);
    }
    printf("--------------------------------\n");


    //错误定义
    //像这种数组的长度为5,但却初始化了10个元素,后面的五个元素是无法访问到的
    //int nums_5[5] = { 1,2,3,4,5,6,7,8,9,10 };
}

/**
 * 一维数组的长度
 */
void LengthOfOneDimensionalArrayTest()
{
    //如果定义数组时规定了数组的长度,那么不管真实的长度是多少,求出来的长度都是之前规定好的长度
    int arr_1[10] = { 1,2,3,4,5 };
    //如果定义数组时规定了数组的长度,那么不管真实的长度是多少,求出来的长度都是之前规定好的长度
    int arr_2[5] = { 1,2,3,4,5 };
    //如果定义数组时没有规定数组的长度,等号右边写了几个元素,数组的长度就是几
    int arr_3[] = { 1,2,3,4,5 };
    printf("数组的长度 = %d\n", sizeof(arr_1) / sizeof(arr_1[0]));
    printf("数组的长度 = %d\n", sizeof(arr_2) / sizeof(arr_2[0]));
    printf("数组的长度 = %d\n", sizeof(arr_3) / sizeof(arr_3[0]));


    /**
     * strlen()方法深入探究
     *     注意: 为什么 strlen(chars_2) 的不是5?
     *     因为 strlen() 方法统计长度时遇到\0才会结束统计长度,是字符串专用方法,不适用于字符数组
     */
    char str[] = { "hello" };
    char chars_1[] = { 'h','e','l','l','O','\0' };
    char chars_2[] = { 'h','e','l','l','O' };
    printf("str长度 = %d, chars_1 = %d, chars_2 = %d\n", strlen(str), strlen(chars_1), strlen(chars_2));
}

/**
 * 一维数组的两个属性
 *  数组的类型
 *  数组的大小
 */
void TwoAttributeOfOneDimensionalArrayTest()
{
    //计算数组所占空间大小的两种方式
    int arr[5] = { 1,2,3,4,5 };
    int size1 = sizeof(int) * 5;
    printf("size1 = %d\n", size1);
    int size2 = sizeof(arr);
    printf("size2 = %d\n", size2);
    char str1[] = { "hello" };
    //注意:字符串的大小为 = 字符个数 * 一个char类型所占长度 + \0的大小 = 字符个数 * 1 + 1
    //注意size3和size4的大小
    int size3 = sizeof(str1);
    printf("size3 = %d\n", size3);
    char str2[5] = { "hello" };
    //注意size3和size4的大小
    int size4 = sizeof(str2);
    printf("size4 = %d\n", size4);


    //计算数组长度大小
    int length1 = sizeof(arr) / sizeof(arr[0]);
    printf("length1 = %d\n", length1);
    char str3[] = { "hello" };
    //计算字符串长度专用方法
    int length2 = strlen(str3);
    printf("length2 = %d\n", length2);
}

/**
 * 查看不同数据类型数组中每一个元素在内存中的物理地址
 */
void ViewMemoryPhysicalAddressOfOneDimensionalArrayTest()
{
    //可以清晰的观察到一个字符占用一个字节
    char str[] = { "hello" };
    for (int i = 0; i < strlen(str); i++)
    {
        printf("%p\n", &str[i]);
    }
    printf("-----------------------------\n");

    //可以清晰观察到一个int类型数据占4个字节
    int nums[] = { 1,2,3,4,5 };
    int length = sizeof(nums) / sizeof(nums[0]);
    for (int i = 0; i < length; i++)
    {
        printf("%p\n", &nums[i]);
    }
}

#if 0
int main()
{
    //DefineOneDimensionalArrayTest();
    //LengthOfOneDimensionalArrayTest();
    //TwoAttributeOfOneDimensionalArrayTest();
    //ViewMemoryPhysicalAddressOfOneDimensionalArrayTest();
    return 0;
}
#endif // 0