#include <stdio.h>
#include <string.h>
#include <assert.h>
char* my_strcat(char* dest , const char* src)
{
    assert(dest && src);
    char* ret = dest;

    while(*dest != '\0')
    {
        dest++;  // 修复：移动指针到字符串末尾
    }

    while((*dest++ = *src++) != '\0'){;}  // 修复警告：添加括号和显式条件
    return ret;
}
int main()
{
    char arr[20] = "hello";
    
    // 验证返回值
    printf("原始arr地址: %p\n", (void*)arr);
    printf("原始内容: %s\n", arr);
    
    char* result = my_strcat(arr, " world");
    
    printf("返回的地址: %p\n", (void*)result);
    printf("拼接后内容: %s\n", arr);
    printf("通过返回值访问: %s\n", result);
    
    // 验证地址是否相同
    if(result == arr) {
        printf("✓ 返回的地址与原始arr地址相同\n");
    } else {
        printf("✗ 地址不同\n");
    }
    
    return 0;
// 字符数组的实际大小
// 当你使用 char arr[] = "hello"; 创建数组时：

// 固定大小：编译器会根据初始化字符串的长度来确定数组大小
// 具体大小：这里创建的是一个长度为6的数组（5个字符 + 1个'\0'终止符）
// 不可扩展：这个数组在栈上分配，大小是固定的，不会自动扩展


}

