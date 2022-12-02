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

void Them_node_p_vaosau_node_q ( list &l , node *p)
{
    int x;
    cout << "Nhap gia tri node q: ";
    cin >> x;
    node *q = khoitaonode ( x);

    // TRƯỜNG HỢP DANH SÁCH CO MỘT PHẦN TỬ VÀ PHÂN TỬ ĐÓ CŨNG CHÍNH LÀ NODE q THÌ BÀI TOÁN SẼ TRỞ THÀNH KỸ THUẬT THÊM VÀO CUỐI
    if (q->data == l.pHead->data && l.pHead->pNext == NULL)
    {
        Themvaocuoi ( l , p) ;
    }
    else
    {
        //   DUYỆT TỪ ĐẦU DANH SÁCH ĐẾN CUỐI DANH SÁCH ĐỂ TÌM NODE q
        for (node *k = l.pHead ; k != NULL ; k = k->pNext)
        {
            // NẾU q CÓ TỒN TẠI THÌ
            if ( q->data == k->data)
            {
                // node *g = k->pNext  ; // CHO NODE g TRỎ ĐẾN NODE NẰM SAU q
                // p-> pNext = g;  // BƯỚC 1: TẠO MỐI LIÊN KẾT TỪ NODE P ĐẾN NODE G => CŨNG CHÍNH LÀ TẠO MỐI LIÊN KẾT TỪ NODE P ĐẾN NODE NẰM SAU q
                // k->pNext = p;   // BƯỚC 2: TẠO MỐI LIÊN KẾT NODE q ĐẾN NODE p =>  CHÍNH LÀ LIÊN KẾT NODE K ĐẾN NODE P
                node *h = khoitaonode ( p->data ) ;  // khởi tạo node h mới để thêm vào sau node q
                node *g = k->pNext ;  // CHO NODE g TRỎ ĐẾN NODE NẰM SAU q
                h-> pNext = g;  // BƯỚC 1: TẠO MỐI LIÊN KẾT TỪ NODE H ĐẾN NODE G => CŨNG CHÍNH LÀ TẠO MỐI LIÊN KẾT TỪ NODE H ĐẾN NODE NẰM SAU q
                k->pNext = h;   // BƯỚC 2: TẠO MỐI LIÊN KẾT NODE q ĐẾN NODE h =>  CHÍNH LÀ LIÊN KẾT NODE K ĐẾN NODE H

            }

        }   
    }
}
void MENU (list &l)
{
    int luachon;
    while (true)
    {
        system( "cls") ;
        cout << "\n\n\t\t==========MENU=========="<< endl;
        cout << "1. Them node vao danh sach" << endl;
        cout << "2. Xuat danh sach  lien ket" << endl;
        cout << "3. Them node p vao sau node q " << endl;
        cout << "0. Thoat" << endl;
        cout << "\t\t========= THOAT==========" << endl;
        int luachon;
        do
        {
            cout << "Nhap vao lua chon: ";
            cin >> luachon;
            if ( luachon < 0 || luachon > 3)
            {
                cout << "Loi, vui long nhap lai " ;
            }
        } while ( luachon < 0 || luachon > 3);
        

        if ( luachon == 1 )
        {
            int x;
            cout << "Nhap gia tri so nguyen: ";
            cin >> x;
            node *p = khoitaonode ( x );
            Themvaocuoi ( l , p);
        }
        else if ( luachon == 2 )
        {
            cout << "Mang danh sach lien ket: " ;
            Xuatdanhsach (l);
            cout << endl;
            system ( "pause") ;
        }
        else if ( luachon == 3)
        {
            int x;
            cout << "Nhap gia tri node p can them vao sau: " ;
            cin >> x;
            node *p = khoitaonode ( x);
            Them_node_p_vaosau_node_q ( l , p) ;
        }  
    }
}


int main ()
{
    node *p; 
    list l;
    Khoitao ( l); 
    MENU ( l);
    system ("pause");
    return 0;
}