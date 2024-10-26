// File script.js này có các chức năng chính sau:

// 1. Xử lý slideshow cho phần showcase phim:
document.addEventListener('DOMContentLoaded', function() {
    const slides = document.querySelectorAll('.showcase-slide');
    const dots = document.querySelectorAll('.control-dot');
    let currentSlide = 0;
    let intervalId;

    // Hiển thị slide được chọn
    function showSlide(index) {
        slides[currentSlide].classList.remove('active');
        dots[currentSlide].classList.remove('active');
        slides[index].classList.add('active');
        dots[index].classList.add('active');
        currentSlide = index;
    }

    // Chuyển đến slide tiếp theo
    function nextSlide() {
        let nextIndex = (currentSlide + 1) % slides.length;
        showSlide(nextIndex);
    }

    // Quay lại slide trước đó
    function prevSlide() {
        let prevIndex = (currentSlide - 1 + slides.length) % slides.length;
        showSlide(prevIndex);
    }

    // Đặt lại hẹn giờ tự động chuyển slide
    function resetAutoSlide() {
        clearInterval(intervalId);
        intervalId = setInterval(nextSlide, 3000);
    }

    // Bắt đầu tự động chuyển đổi slide
    resetAutoSlide();

    // Xử lý sự kiện phím mũi tên để điều khiển slideshow
    document.addEventListener('keydown', function(e) {
        if (e.key === 'ArrowRight') {
            nextSlide();
            resetAutoSlide();
        } else if (e.key === 'ArrowLeft') {
            prevSlide();
            resetAutoSlide();
        }
    });

    // Xử lý sự kiện click cho các nút điều khiển (dots)
    dots.forEach((dot, index) => {
        dot.addEventListener('click', () => {
            showSlide(index);
            resetAutoSlide();
        });
    });

    // Tạm dừng tự động chuyển đổi khi hover chuột vào showcase
    const showcase = document.querySelector('.movie-showcase');
    showcase.addEventListener('mouseenter', function() {
        clearInterval(intervalId);
    });
    showcase.addEventListener('mouseleave', resetAutoSlide);
});

// 2. Xử lý hiệu ứng hover cho các thẻ phim:
document.querySelectorAll('.movie-card').forEach(card => {
    card.addEventListener('mouseenter', () => {
        card.querySelector('.movie-info').style.opacity = '1';
    });
    card.addEventListener('mouseleave', () => {
        card.querySelector('.movie-info').style.opacity = '0';
    });
});

// Tóm lại, file này quản lý slideshow và hiệu ứng hover cho các thẻ phim trên trang web.
