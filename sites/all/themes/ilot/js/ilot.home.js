(function ($) {

    Drupal.behaviors.ilotHome = {

    attach: function (context, settings) {

         console.log("js home");

        var swiper = new Swiper('.node-accueil .swiper-container', {

            pagination: '.swiper-pagination',
            paginationClickable: true,
            nextButton: '.swiper-button-next',
            prevButton: '.swiper-button-prev',
            spaceBetween: 30,
            autoplay : 10000

        });

    }

};

})(jQuery);
