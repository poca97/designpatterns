1. Observer là design pattern dùng để tạo ra mối quan hệ 1-n giữa các đối tượng, khi một đối tượng thay đổi trạng thái, tất cả các phụ thuộc của nó sẽ được thông báo và cập nhật tự động. 
  - IObserver: Cập nhật những thay đổi của Observer(Database)
  - ISubject: Cho phép các observers có thể đăng ký và nhận thông báo khi có sự kiện xảy ra
  - Datbase: Implement registerObserver, removeObserver, và notifyObservers từ ISubject để thực thi
      + Để lưu thông tin về các observer thì ở đây mình sẽ dùng một biến member kiểu vector<IObserver*> là mObservers
      + Khi muốn đăng ký một observer với subject thì cần call method registerObserver của subject và truyền vào pointer đến observer. Sau đó, subject – đối tượng của class Database sẽ call hàm pushback của vector để thêm pointer đó vào vector mObservers để quản lý
      + Khi muốn xóa một observer đã đăng ký thì tìm pointer của observer đó trong mObservers và xóa nó đi
      + Khi user làm gì đó với cơ sở dữ liệu, ví dụ xóa một bản ghi, thì user sẽ gọi phương thức editRecord của class Database
      + Khi muốn notify observer ta chỉ việc duyệt mObservers sau đó cập nhật vào ISubject
2. Mediator: (mô hình trung gian) được sử dụng để giảm sự phức tạp trong “giao tiếp” giữa các lớp và các đối tượng. Mô hình này cung cấp một lớp trung gian có nhiệm vụ xử lý thông tin liên lạc giữa các tầng lớp, hỗ trợ bảo trì mã code dễ dàng bằng cách khớp nối lỏng lẻo.
  - ColleageA, ColleageB: Giữ vai trò như 2 người dùng
  - Colleage: mỗi Colleage duy trì 1 Mediator, khi giao tiếp mỗi Colleage sẽ gửi trực tiếp tin nhắn đến ConcreteMediator
  - ConcreteMediator: Tiếp nhận tin nhắn từ Colleage, và là nhân tố quyết định thông tin sẽ được gửi đến người dùng nào
  - Mediator: Làm giảm sự ghép nối của mỗi Colleage, có thể thay đổi độc lập
