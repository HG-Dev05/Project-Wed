document.addEventListener('DOMContentLoaded', function() {
    const slides = document.querySelectorAll('.showcase-slide');
    const dots = document.querySelectorAll('.control-dot');
    let currentSlide = 0;
    let intervalId;

    function showSlide(index) {
        slides[currentSlide].classList.remove('active');
        dots[currentSlide].classList.remove('active');
        slides[index].classList.add('active');
        dots[index].classList.add('active');
        currentSlide = index;
    }

    function nextSlide() {
        let nextIndex = (currentSlide + 1) % slides.length;
        showSlide(nextIndex);
    }

    function prevSlide() {
        let prevIndex = (currentSlide - 1 + slides.length) % slides.length;
        showSlide(prevIndex);
    }

    function resetAutoSlide() {
        clearInterval(intervalId);
        intervalId = setInterval(nextSlide, 3000);
    }

    // Bắt đầu tự động chuyển đổi slide
    resetAutoSlide();

    // Xử lý sự kiện phím mũi tên
    document.addEventListener('keydown', function(e) {
        if (e.key === 'ArrowRight') {
            nextSlide();
            resetAutoSlide();
        } else if (e.key === 'ArrowLeft') {
            prevSlide();
            resetAutoSlide();
        }
    });

    // Xử lý sự kiện click cho các nút điều khiển
    dots.forEach((dot, index) => {
        dot.addEventListener('click', () => {
            showSlide(index);
            resetAutoSlide();
        });
    });

    // Thêm xử lý sự kiện hover để tạm dừng tự động chuyển đổi
    const showcase = document.querySelector('.movie-showcase');
    showcase.addEventListener('mouseenter', function() {
        clearInterval(intervalId);
    });
    showcase.addEventListener('mouseleave', resetAutoSlide);
});

document.querySelectorAll('.movie-card').forEach(card => {
    card.addEventListener('mouseenter', () => {
        card.querySelector('.movie-info').style.opacity = '1';
    });
    card.addEventListener('mouseleave', () => {
        card.querySelector('.movie-info').style.opacity = '0';
    });
});
