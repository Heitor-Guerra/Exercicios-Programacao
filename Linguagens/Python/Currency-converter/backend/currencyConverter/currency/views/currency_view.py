from rest_framework.response import Response
from rest_framework.views import APIView

from currency.services.currency_service import (
    CurrencyService,
)


class CurrencyView(APIView):
    def get(self, request):
        service = CurrencyService
        currencies = service.get_all_currencies()
        return Response(
            [
                {
                    "name": c.name,
                    "acronym": c.acronym,
                    "symbol": c.symbol,
                    "rate": float(c.usd_rate),
                }
                for c in currencies
            ]
        )


class CurrencyCreateView(APIView):
    def post(self, request):
        service = CurrencyService()

        try:
            currency = service.create_currency(
                name=request.data["name"],
                acronym=request.data["acronym"],
                symbol=request.data["symbol"],
                usd_rate=request.data["usd_rate"],
            )
            return Response({"status": "created"}, status=201)
        except ValueError as e:
            return Response({"error": str(e)}, status=400)


class CurrencyConvertView(APIView):
    def post(self, request):
        service = CurrencyService()

        try:
            a: float = service.convert(
                value=request.data["value"],
                source=request.data["from"],
                dest=request.data["to"],
            )

            return Response({"value": a}, status=200)
        except ValueError as e:
            return Response({"error": str(e)}, status=400)


class CurrencyConvertPathView(APIView):
    def get(self, value, source, dest):
        service = CurrencyService()

        try:
            a: float = service.convert(value, source, dest)

            return Response({"value": a}, status=200)
        except ValueError as e:
            return Response({"error": str(e)}, status=400)
