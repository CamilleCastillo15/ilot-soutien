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
         		$(".details_conseil").removeClass(desti);
         	}

         	
         	var go = $("#"+$(this).attr('id')+"_textes");
         	go.addClass("active");
         	$(this).addClass("active");

         	var _y = $(this).offset().top;
         	if(_y < 700){
         		desti = "top";
         	}else{
         		desti = "bottom";
         	}

         	$(".details_conseil").addClass(desti);

         	currentBt = $(this);

         	currentItem = go;

	    });

    }

};

})(jQuery);
