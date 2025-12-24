#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Hàm t?o node m?i
Node* createNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

// Thêm node vào cu?i danh sách
void insertLast(Node*& head, int x) {
    Node* p = createNode(x);
    if (head == NULL) {
        head = p;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = p;
    }
}

// In danh sách
void printList(Node* head) {
    for (Node* p = head; p != NULL; p = p->next)
        cout << p->data << " ";
    cout << endl;
}

// Thêm ph?n t? vào v? trí b?t k?
void insertAt(Node*& head, int x, int pos) {
    Node* p = createNode(x);
    if (pos <= 1 || head == NULL) {
        p->next = head;
        head = p;
        return;
    }
    Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;
    if (temp == NULL) return;
    p->next = temp->next;
    temp->next = p;
}

// Ð?m s? ph?n t? có giá tr? = k
int countK(Node* head, int k) {
    int count = 0;
    for (Node* p = head; p != NULL; p = p->next)
        if (p->data == k) count++;
    return count;
}

// Ki?m tra có 3 s? ch?n duong d?ng c?nh nhau
void checkEvenTriplet(Node* head) {
    int pos = 1;
    bool found = false;
    Node* p = head;
    while (p && p->next && p->next->next) {
        if (p->data > 0 && p->data % 2 == 0 &&
            p->next->data > 0 && p->next->data % 2 == 0 &&
            p->next->next->data > 0 && p->next->next->data % 2 == 0) {
            cout << "Ba so chan dung canh nhau tai vi tri " << pos << " - "
                 << pos + 2 << endl;
            found = true;
        }
        p = p->next;
        pos++;
    }
    if (!found)
        cout << "Khong co 3 so chan duong dung canh nhau.\n";
}

// S?p x?p danh sách tang d?n
void sortList(Node*& head) {
    for (Node* p = head; p != NULL; p = p->next)
        for (Node* q = p->next; q != NULL; q = q->next)
            if (p->data > q->data)
                swap(p->data, q->data);
}

// Ki?m tra s? nguyên t?
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

// Xóa các s? nguyên t?
void deletePrimes(Node*& head) {
    while (head && isPrime(head->data)) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    Node* p = head;
    while (p && p->next) {
        if (isPrime(p->next->data)) {
            Node* temp = p->next;
            p->next = temp->next;
            delete temp;
        } else p = p->next;
    }
}

// Xóa ph?n t? trùng nhau, gi? l?i 1
void removeDuplicates(Node*& head) {
    for (Node* p = head; p != NULL; p = p->next) {
        Node* q = p;
        while (q->next != NULL) {
            if (q->next->data == p->data) {
                Node* temp = q->next;
                q->next = temp->next;
                delete temp;
            } else q = q->next;
        }
    }
}

int main() {
    Node* head = NULL;
    string s;
    cout << "Nhap cac so, nhap '#' de dung: ";
    while (true) {
        cin >> s;
        if (s == "#") break;
        insertLast(head, stoi(s));
    }

    cout << "\nDanh sach vua nhap: ";
    printList(head);

    int x, pos;
    cout << "\nNhap phan tu can chen: ";
    cin >> x;
    cout << "Nhap vi tri can chen: ";
    cin >> pos;
    insertAt(head, x, pos);
    cout << "Danh sach sau khi chen: ";
    printList(head);

    int k;
    cout << "\nNhap k (k != 0): ";
    cin >> k;
    cout << "So phan tu co gia tri = " << k << " la: " << countK(head, k) << endl;

    cout << "\nKiem tra 3 so chan duong dung canh nhau:\n";
    checkEvenTriplet(head);

    cout << "\nDanh sach sau khi sap xep tang dan: ";
    sortList(head);
    printList(head);

    cout << "\nXoa tat ca so nguyen to trong danh sach.\n";
    deletePrimes(head);
    printList(head);

    cout << "\nXoa cac phan tu trung nhau, chi giu lai 1 so:\n";
    removeDuplicates(head);
    printList(head);

    return 0;
}

