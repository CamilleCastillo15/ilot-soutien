(function ($) {

    Drupal.behaviors.ilotHome = {

    attach: function (context, settings) {

    	var currentItem = null;
    	var currentBt = null;
    	var desti = "top";

         $('.img-admin').click(function(){
	    	
         	
         	if(currentItem != null){
         		currentItem.removeClass("active");
         	}

         	if(currentBt != null){
         		currentBt.removeClass("active");
//         		$(".details_conseil").removeClass(desti);
         	}


         	var go = $("#"+$(this).attr('id')+"_textes");
         	go.addClass("active");
         	$(this).addClass("active");

         	var _y = $(this).offset().top;

            console.log(_y);

         	if(_y < 700){
         		desti = "top";
         	}else{
         		desti = "bottom";
         	}

//         	$(".details_conseil").addClass(desti);
//            $(".details_conseil."+desti).addClass("visible");

            if($(this).hasClass('img-membres-bureau')) {

                $(".details_conseil.top").addClass("visible");
                $(".details_conseil.bottom").removeClass("visible");

            } else {

                $(".details_conseil.bottom").addClass("visible");
                $(".details_conseil.top").removeClass("visible");

            }

         	currentBt = $(this);

         	currentItem = go;

	    });

    }

};

})(jQuery);
