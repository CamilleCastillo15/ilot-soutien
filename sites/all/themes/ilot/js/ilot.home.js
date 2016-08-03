(function ($) {

    Drupal.behaviors.ilotHome = {

    attach: function (context, settings) {

      

        var swiper = new Swiper('.node-accueil .swiper-container', {

            pagination: '.swiper-pagination',
            paginationClickable: true,
            nextButton: '.swiper-button-next',
            prevButton: '.swiper-button-prev',
            spaceBetween: 0,
            autoplay : 10000

        });

    }

};

})(jQuery);
