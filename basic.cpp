// NHẬP DANH SÁCH LK CÁC SỐ NGUYÊN. TÌM GÁI TRỊ LỚN NHẤT TRONG DANH SÁCH
#include <iostream>
using namespace std;

// khai báo cấu trúc 1 cái node
struct node
{
    int data;
    node *pNext;
};

// khai báo cấu trúc dslk đơn
struct list
{

    node *pHead;
    node *pTail;
};

//=====KHỞI TẠO CẤU TRÚC DS LIÊN KẾT ĐƠN CÁC SỐ NGUYÊN=========- //
void Khoitao ( list &l)
{
    // cho 2 node trỏ dến NULL vì DSLK chưa có phần tử
    l.pHead = NULL;
    l.pTail = NULL;
}

// HÀM KHỞI TẠO 1 CÁI NULL
node *khoitaonode ( int x)
{
    node *p = new node ; // CẤP PHÁT BỘ NHỚ CHO NODE P
    p-> data = x;     // TRUYỀN GIÁ TRỊ X VAO CHO DATA
    p->pNext = NULL;    // ĐẦU TIÊN KHAI BÁO NODE THÌ NODE ĐÓ CHƯA CÓ LIÊN KẾT ĐẾN NODE NÀO HẾT 
    return p;  //TRẢ VỀ NODE P VỪA KHỞI TẠO
}

// HÀM THÊM P VÀO ĐẦU DANH SÁCH LIÊN KẾT
void Themvaodau ( list &l , node *p)
{
    if ( l.pHead == NULL)
    {
        l.pHead = l.pTail = p; //NODE ĐẦU CŨNG LÀ NODE CUỐI VÀ LÀ P
    }
    else
    {
        p->pNext = l.pHead; // CHO CON TRỎ CỦA NODE CẦN THÊM LA NODE P LIÊN KẾT VỚI NODE DẦU P.HEAD
        l.pHead = p; // CẬP NHẬT LẠI NODE ĐẦU LÀ NODE P
    }
}

// HÀM THÊM NODE P VÀO CUỐI DANH SÁCH LIÊN KẾT

void Themvaocuoi ( list &l , node *p)
{
    if ( l.pHead == NULL)
    {
        l.pHead = l.pTail = p; //NODE ĐẦU CŨNG LÀ NODE CUỐI VÀ LÀ P
    }
    else
    {
        l.pTail-> pNext = p;   // CHO CON TRỎ CỦA NODE CẦN THÊM LA NODE P LIÊN KẾT VỚI NODE DẦU P.HEAD
        l.pTail = p;   // CẬP NHẬT LẠI NODE ĐẦU LÀ NODE P
    }

}

// HÀM XUẤT DS LK ĐƠN
void Xuatdanhsach ( list l)
{
    // for ( int i = 0 : i < n ; i++)
    for ( node *k = l.pHead ; k != NULL ; k=k->pNext)
    {
        cout << k->data << " ";
    }
}

int main ()
{
    list l;
    Khoitao ( l); 

    int n;
    cout << "\n\nNhap vao so luong can them: ";
    cin >> n;
    for ( int i=1 ; i <= n ; i++)
    {
        int x;
        cout << "Nhap vao gia tri so nguyen thu " << i << ": "  ;
        cin >> x;
        node *p = khoitaonode ( x); // KHỞI TẠO 1 CÁI NODE SỐ NGUYÊN
        Themvaodau ( l , p); // THÊM NODE P VÀO ĐẦU DANH SÁCH LIÊN KẾT ĐƠN
    }
    cout <<"\n DANH SACH LIEN KET DON\n" ;
    Xuatdanhsach ( l);
    cout << endl;
    system ( "pause");
    return 0;




}